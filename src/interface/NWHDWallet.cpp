//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWHDWallet.h>

#include "../Coin.h"
#include "../HDWallet.h"
#include "../Mnemonic.h"

using namespace NW;


struct NWHDWallet *_Nullable NWHDWalletCreate(int strength, NWString *_Nonnull passphrase) {
    try {
        return new NWHDWallet{ HDWallet(strength, NWStringUTF8Bytes(passphrase)) };
    } catch (...) {
        return nullptr;
    }
}

struct NWHDWallet *_Nullable NWHDWalletCreateWithMnemonic(NWString *_Nonnull mnemonic, NWString *_Nonnull passphrase) {
try {
return new NWHDWallet{ HDWallet(NWStringUTF8Bytes(mnemonic), NWStringUTF8Bytes(passphrase)) };
} catch (...) {
return nullptr;
}
}

struct NWHDWallet *_Nullable NWHDWalletCreateWithMnemonicCheck(NWString *_Nonnull mnemonic, NWString *_Nonnull passphrase, bool check) {
try {
return new NWHDWallet{ HDWallet(NWStringUTF8Bytes(mnemonic), NWStringUTF8Bytes(passphrase), check) };
} catch (...) {
return nullptr;
}
}

struct NWHDWallet *_Nullable NWHDWalletCreateWithEntropy(NWData *_Nonnull entropy, NWString *_Nonnull passphrase) {
try {
auto* d = reinterpret_cast<const Data*>(entropy);
return new NWHDWallet{ HDWallet(*d, NWStringUTF8Bytes(passphrase)) };
} catch (...) {
return nullptr;
}
}

void NWHDWalletDelete(struct NWHDWallet *wallet) {
    delete wallet;
}

NWData *_Nonnull NWHDWalletSeed(struct NWHDWallet *_Nonnull wallet) {
    return NWDataCreateWithBytes(wallet->impl.getSeed().data(), HDWallet::seedSize);
}

NWString *_Nonnull NWHDWalletMnemonic(struct NWHDWallet *_Nonnull wallet){
    return NWStringCreateWithUTF8Bytes(wallet->impl.getMnemonic().c_str());
}

NWData *_Nonnull NWHDWalletEntropy(struct NWHDWallet *_Nonnull wallet) {
    return NWDataCreateWithBytes(wallet->impl.getEntropy().data(), wallet->impl.getEntropy().size());
}

struct NWPrivateKey *_Nonnull NWHDWalletGetMasterKey(struct NWHDWallet *_Nonnull wallet, NWCurve curve) {
    return new NWPrivateKey{ wallet->impl.getMasterKey(curve) };
}

struct NWPrivateKey *_Nonnull NWHDWalletGetKeyForCoin(struct NWHDWallet *wallet, NWCoinType coin) {
    auto derivationPath = NW::derivationPath(coin);
    return new NWPrivateKey{ wallet->impl.getKey(coin, derivationPath) };
}

NWString *_Nonnull NWHDWalletGetAddressForCoin(struct NWHDWallet *wallet, NWCoinType coin) {
    auto derivationPath = NW::derivationPath(coin);
    PrivateKey privateKey = wallet->impl.getKey(coin, derivationPath);
    std::string address = deriveAddress(coin, privateKey);
    return NWStringCreateWithUTF8Bytes(address.c_str());
}

struct NWPrivateKey *_Nonnull NWHDWalletGetKey(struct NWHDWallet *_Nonnull wallet, enum NWCoinType coin, NWString *_Nonnull derivationPath) {
    auto& s = *reinterpret_cast<const std::string*>(derivationPath);
    const auto path = DerivationPath(s);
    return new NWPrivateKey{ wallet->impl.getKey(coin, path) };
}

struct NWPrivateKey *_Nonnull NWHDWalletGetDerivedKey(struct NWHDWallet *_Nonnull wallet, enum NWCoinType coin, uint32_t account, uint32_t change, uint32_t address) {
    const auto derivationPath = DerivationPath(NW::purpose(coin), NW::slip44Id(coin), account, change, address);
    return new NWPrivateKey{ wallet->impl.getKey(coin, derivationPath) };
}

NWString *_Nonnull NWHDWalletGetExtendedPrivateKey(struct NWHDWallet *wallet, NWPurpose purpose, NWCoinType coin, NWHDVersion version) {
    return new std::string(wallet->impl.getExtendedPrivateKey(purpose, coin, version));
}

NWString *_Nonnull NWHDWalletGetExtendedPublicKey(struct NWHDWallet *wallet, NWPurpose purpose, NWCoinType coin, NWHDVersion version) {
    return new std::string(wallet->impl.getExtendedPublicKey(purpose, coin, version));
}

NWString *_Nonnull NWHDWalletGetExtendedPrivateKeyAccount(struct NWHDWallet *wallet, NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account) {
    return new std::string(wallet->impl.getExtendedPrivateKeyAccount(purpose, coin, derivation, version, account));
}

NWString *_Nonnull NWHDWalletGetExtendedPublicKeyAccount(struct NWHDWallet *wallet, NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account) {
    return new std::string(wallet->impl.getExtendedPublicKeyAccount(purpose, coin, derivation, version, account));
}

NWString *_Nonnull NWHDWalletGetExtendedPrivateKeyDerivation(struct NWHDWallet *wallet, NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version) {
    return new std::string(wallet->impl.getExtendedPrivateKeyDerivation(purpose, coin, derivation, version));
}

NWString *_Nonnull NWHDWalletGetExtendedPublicKeyDerivation(struct NWHDWallet *wallet, NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version) {
    return new std::string(wallet->impl.getExtendedPublicKeyDerivation(purpose, coin, derivation, version));
}

NWPublicKey *NWHDWalletGetPublicKeyFromExtended(NWString *_Nonnull extended, enum NWCoinType coin, NWString *_Nonnull derivationPath) {
const auto derivationPathObject = DerivationPath(*reinterpret_cast<const std::string*>(derivationPath));
auto publicKey = HDWallet::getPublicKeyFromExtended(*reinterpret_cast<const std::string*>(extended), coin, derivationPathObject);
if (!publicKey) {
return nullptr;
}
return new NWPublicKey{ PublicKey(*publicKey) };
}
