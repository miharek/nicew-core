// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "HDWallet.h"

#include "Base58.h"
#include "BinaryCoding.h"
#include "Bitcoin/SegwitAddress.h"
#include "Coin.h"
#include "Mnemonic.h"
#include "memory/memzero_wrapper.h"

#include <NiceWCore/NWHRP.h>
#include <NiceWCore/NWPublicKeyType.h>

#include <TrezorCrypto/options.h>

#include <TrezorCrypto/bip32.h>
#include <TrezorCrypto/bip39.h>
#include <TrezorCrypto/cardano.h>
#include <TrezorCrypto/curves.h>

#include <array>
#include <cstring>

using namespace NW;

namespace {

uint32_t fingerprint(HDNode* node, Hash::Hasher hasher);
std::string serialize(const HDNode* node, uint32_t fingerprint, uint32_t version, bool use_public, Hash::Hasher hasher);
bool deserialize(const std::string& extended, NWCurve curve, Hash::Hasher hasher, HDNode* node);
HDNode getNode(const HDWallet& wallet, NWCurve curve, const DerivationPath& derivationPath);
HDNode getMasterNode(const HDWallet& wallet, NWCurve curve);

const char* curveName(NWCurve curve);
} // namespace

const int MnemonicBufLength = Mnemonic::MaxWords * (BIP39_MAX_WORD_LENGTH + 3) + 20; // some extra slack

HDWallet::HDWallet(int strength, const std::string& passphrase)
    : passphrase(passphrase) {
    char buf[MnemonicBufLength];
    const char* mnemonic_chars = mnemonic_generate(strength, buf, MnemonicBufLength);
    if (mnemonic_chars == nullptr) {
        throw std::invalid_argument("Invalid strength");
    }
    mnemonic = mnemonic_chars;
    NW::memzero(buf, MnemonicBufLength);
    updateSeedAndEntropy();
}

HDWallet::HDWallet(const std::string& mnemonic, const std::string& passphrase, const bool check)
    : mnemonic(mnemonic), passphrase(passphrase) {
    if (mnemonic.length() == 0 ||
        (check && !Mnemonic::isValid(mnemonic))) {
        throw std::invalid_argument("Invalid mnemonic");
    }
    updateSeedAndEntropy(check);
}

HDWallet::HDWallet(const Data& entropy, const std::string& passphrase)
    : passphrase(passphrase) {
    char buf[MnemonicBufLength];
    const char* mnemonic_chars = mnemonic_from_data(entropy.data(), static_cast<int>(entropy.size()), buf, MnemonicBufLength);
    if (mnemonic_chars == nullptr) {
        throw std::invalid_argument("Invalid mnemonic data");
    }
    mnemonic = mnemonic_chars;
    NW::memzero(buf, MnemonicBufLength);
    updateSeedAndEntropy();
}

HDWallet::~HDWallet() {
    std::fill(seed.begin(), seed.end(), 0);
    std::fill(mnemonic.begin(), mnemonic.end(), 0);
    std::fill(passphrase.begin(), passphrase.end(), 0);
}

void HDWallet::updateSeedAndEntropy(bool check) {
    assert(!check || Mnemonic::isValid(mnemonic)); // precondition

    // generate seed from mnemonic
    mnemonic_to_seed(mnemonic.c_str(), passphrase.c_str(), seed.data(), nullptr);

    // generate entropy bits from mnemonic
    Data entropyRaw((Mnemonic::MaxWords * Mnemonic::BitsPerWord) / 8);
    // entropy is truncated to fully bytes, 4 bytes for each 3 words (=33 bits)
    auto entropyBytes = mnemonic_to_bits(mnemonic.c_str(), entropyRaw.data()) / 33 * 4;
    // copy to truncate
    entropy = data(entropyRaw.data(), entropyBytes);
    assert(!check || entropy.size() > 10);
}

PrivateKey HDWallet::getMasterKey(NWCurve curve) const {
    auto node = getMasterNode(*this, curve);
    auto data = Data(node.private_key, node.private_key + PrivateKey::_size);
    return PrivateKey(data);
}

PrivateKey HDWallet::getMasterKeyExtension(NWCurve curve) const {
    auto node = getMasterNode(*this, curve);
    auto data = Data(node.private_key_extension, node.private_key_extension + PrivateKey::_size);
    return PrivateKey(data);
}

PrivateKey HDWallet::getKey(NWCoinType coin, NWDerivation derivation) const {
    const auto path = NW::derivationPath(coin, derivation);
    return getKey(coin, path);
}

DerivationPath HDWallet::cardanoStakingDerivationPath(const DerivationPath& path) {
    DerivationPath stakingPath = path;
    stakingPath.indices[3].value = 2;
    stakingPath.indices[4].value = 0;
    return stakingPath;
}

PrivateKey HDWallet::getKey(NWCoinType coin, const DerivationPath& derivationPath) const {
    const auto curve = NWCoinTypeCurve(coin);
    const auto privateKeyType = PrivateKey::getType(curve);
    auto node = getNode(*this, curve, derivationPath);
    switch (privateKeyType) {
    case NWPrivateKeyTypeCardano: {
        if (derivationPath.indices.size() < 4 || derivationPath.indices[3].value > 1) {
            // invalid derivation path
            return PrivateKey(Data(PrivateKey::cardanoKeySize));
        }
        const DerivationPath stakingPath = cardanoStakingDerivationPath(derivationPath);

        auto pkData = Data(node.private_key, node.private_key + PrivateKey::_size);
        auto extData = Data(node.private_key_extension, node.private_key_extension + PrivateKey::_size);
        auto chainCode = Data(node.chain_code, node.chain_code + PrivateKey::_size);

        // repeat with staking path
        const auto node2 = getNode(*this, curve, stakingPath);
        auto pkData2 = Data(node2.private_key, node2.private_key + PrivateKey::_size);
        auto extData2 = Data(node2.private_key_extension, node2.private_key_extension + PrivateKey::_size);
        auto chainCode2 = Data(node2.chain_code, node2.chain_code + PrivateKey::_size);

        NW::memzero(&node);
        return PrivateKey(pkData, extData, chainCode, pkData2, extData2, chainCode2);
    }

    case NWPrivateKeyTypeDefault:
    default:
        // default path
        auto data = Data(node.private_key, node.private_key + PrivateKey::_size);
        NW::memzero(&node);
        return PrivateKey(data);
    }
}

std::string HDWallet::getRootKey(NWCoinType coin, NWHDVersion version) const {
    const auto curve = NWCoinTypeCurve(coin);
    auto node = getMasterNode(*this, curve);
    return serialize(&node, 0, version, false, base58Hasher(coin));
}

std::string HDWallet::deriveAddress(NWCoinType coin) const {
    return deriveAddress(coin, NWDerivationDefault);
}

std::string HDWallet::deriveAddress(NWCoinType coin, NWDerivation derivation) const {
    const auto derivationPath = NW::derivationPath(coin, derivation);
    return NW::deriveAddress(coin, getKey(coin, derivationPath), derivation);
}

std::string HDWallet::getExtendedPrivateKeyAccount(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account) const {
    if (version == NWHDVersionNone) {
        return "";
    }

    const auto curve = NWCoinTypeCurve(coin);
    const auto path = NW::derivationPath(coin, derivation);
    auto derivationPath = DerivationPath({DerivationPathIndex(purpose, true), DerivationPathIndex(path.coin(), true)});
    auto node = getNode(*this, curve, derivationPath);
    auto fingerprintValue = fingerprint(&node, publicKeyHasher(coin));
    hdnode_private_ckd(&node, account + 0x80000000);
    return serialize(&node, fingerprintValue, version, false, base58Hasher(coin));
}

std::string HDWallet::getExtendedPublicKeyAccount(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account) const {
    if (version == NWHDVersionNone) {
        return "";
    }

    const auto curve = NWCoinTypeCurve(coin);
    const auto path = NW::derivationPath(coin, derivation);
    auto derivationPath = DerivationPath({DerivationPathIndex(purpose, true), DerivationPathIndex(path.coin(), true)});
    auto node = getNode(*this, curve, derivationPath);
    auto fingerprintValue = fingerprint(&node, publicKeyHasher(coin));
    hdnode_private_ckd(&node, account + 0x80000000);
    hdnode_fill_public_key(&node);
    return serialize(&node, fingerprintValue, version, true, base58Hasher(coin));
}

std::optional<PublicKey> HDWallet::getPublicKeyFromExtended(const std::string& extended, NWCoinType coin, const DerivationPath& path) {
    const auto curve = NW::curve(coin);
    const auto hasher = NW::base58Hasher(coin);

    auto node = HDNode{};
    if (!deserialize(extended, curve, hasher, &node)) {
        return {};
    }
    if (node.curve->params == nullptr) {
        return {};
    }
    hdnode_public_ckd(&node, path.change());
    hdnode_public_ckd(&node, path.address());
    hdnode_fill_public_key(&node);

    // These public key type are not applicable.  Handled above, as node.curve->params is null
    assert(curve != NWCurveED25519 && curve != NWCurveED25519Blake2bNano && curve != NWCurveED25519ExtendedCardano && curve != NWCurveCurve25519);
    NWPublicKeyType keyType = NW::publicKeyType(coin);
    if (curve == NWCurveSECP256k1) {
        auto pubkey = PublicKey(Data(node.public_key, node.public_key + 33), NWPublicKeyTypeSECP256k1);
        if (keyType == NWPublicKeyTypeSECP256k1Extended) {
            return pubkey.extended();
        } else {
            return pubkey;
        }
    } else if (curve == NWCurveNIST256p1) {
        auto pubkey = PublicKey(Data(node.public_key, node.public_key + 33), NWPublicKeyTypeNIST256p1);
        if (keyType == NWPublicKeyTypeNIST256p1Extended) {
            return pubkey.extended();
        } else {
            return pubkey;
        }
    }
    return {};
}

std::optional<PrivateKey> HDWallet::getPrivateKeyFromExtended(const std::string& extended, NWCoinType coin, const DerivationPath& path) {
    const auto curve = NW::curve(coin);
    const auto hasher = NW::base58Hasher(coin);

    auto node = HDNode{};
    if (!deserialize(extended, curve, hasher, &node)) {
        return {};
    }
    hdnode_private_ckd(&node, path.change());
    hdnode_private_ckd(&node, path.address());

    return PrivateKey(Data(node.private_key, node.private_key + 32));
}

namespace {

uint32_t fingerprint(HDNode* node, Hash::Hasher hasher) {
    hdnode_fill_public_key(node);
    auto digest = Hash::hash(hasher, node->public_key, 33);
    return ((uint32_t)digest[0] << 24) + (digest[1] << 16) + (digest[2] << 8) + digest[3];
}

std::string serialize(const HDNode* node, uint32_t fingerprint, uint32_t version, bool use_public, Hash::Hasher hasher) {
    Data node_data;
    node_data.reserve(78);

    encode32BE(version, node_data);
    node_data.push_back(static_cast<uint8_t>(node->depth));
    encode32BE(fingerprint, node_data);
    encode32BE(node->child_num, node_data);
    node_data.insert(node_data.end(), node->chain_code, node->chain_code + 32);
    if (use_public) {
        node_data.insert(node_data.end(), node->public_key, node->public_key + 33);
    } else {
        node_data.push_back(0);
        node_data.insert(node_data.end(), node->private_key, node->private_key + 32);
    }

    return Base58::bitcoin.encodeCheck(node_data, hasher);
}

bool deserialize(const std::string& extended, NWCurve curve, Hash::Hasher hasher, HDNode* node) {
    NW::memzero(node);
    const char* curveNameStr = curveName(curve);
    if (curveNameStr == nullptr || ::strlen(curveNameStr) == 0) {
        return false;
    }
    node->curve = get_curve_by_name(curveNameStr);
    assert(node->curve != nullptr);

    const auto node_data = Base58::bitcoin.decodeCheck(extended, hasher);
    if (node_data.size() != 78) {
        return false;
    }

    uint32_t version = decode32BE(node_data.data());
    if (NWHDVersionIsPublic(static_cast<NWHDVersion>(version))) {
        std::copy(node_data.begin() + 45, node_data.begin() + 45 + 33, node->public_key);
    } else if (NWHDVersionIsPrivate(static_cast<NWHDVersion>(version))) {
        if (node_data[45]) { // invalid data
            return false;
        }
        std::copy(node_data.begin() + 46, node_data.begin() + 46 + 32, node->private_key);
    } else {
        return false; // invalid version
    }
    node->depth = node_data[4];
    node->child_num = decode32BE(node_data.data() + 9);
    std::copy(node_data.begin() + 13, node_data.begin() + 13 + 32, node->chain_code);
    return true;
}

HDNode getNode(const HDWallet& wallet, NWCurve curve, const DerivationPath& derivationPath) {
    const auto privateKeyType = PrivateKey::getType(curve);
    auto node = getMasterNode(wallet, curve);
    for (auto& index : derivationPath.indices) {
        switch (privateKeyType) {
        case NWPrivateKeyTypeCardano:
            hdnode_private_ckd_cardano(&node, index.derivationIndex());
            break;
        case NWPrivateKeyTypeDefault:
        default:
            hdnode_private_ckd(&node, index.derivationIndex());
            break;
        }
    }
    return node;
}

HDNode getMasterNode(const HDWallet& wallet, NWCurve curve) {
    const auto privateKeyType = PrivateKey::getType(curve);
    HDNode node;
    switch (privateKeyType) {
    case NWPrivateKeyTypeCardano: {
        // Derives the root Cardano HDNode from a passphrase and the entropy encoded in
        // a BIP-0039 mnemonic using the Icarus derivation (V2) scheme
        const auto entropy = wallet.getEntropy();
        uint8_t secret[CARDANO_SECRET_LENGTH];
        secret_from_entropy_cardano_icarus((const uint8_t*)"", 0, entropy.data(), int(entropy.size()), secret, nullptr);
        hdnode_from_secret_cardano(secret, &node);
        NW::memzero(secret, CARDANO_SECRET_LENGTH);
        break;
    }
    case NWPrivateKeyTypeDefault:
    default:
        hdnode_from_seed(wallet.getSeed().data(), HDWallet::seedSize, curveName(curve), &node);
        break;
    }
    return node;
}

const char* curveName(NWCurve curve) {
    switch (curve) {
    case NWCurveSECP256k1:
        return SECP256K1_NAME;
    case NWCurveED25519:
        return ED25519_NAME;
    case NWCurveED25519Blake2bNano:
        return ED25519_BLAKE2B_NANO_NAME;
    case NWCurveED25519ExtendedCardano:
        return ED25519_CARDANO_NAME;
    case NWCurveNIST256p1:
        return NIST256P1_NAME;
    case NWCurveCurve25519:
        return CURVE25519_NAME;
    case NWCurveNone:
    default:
        return "";
    }
}

} // namespace
