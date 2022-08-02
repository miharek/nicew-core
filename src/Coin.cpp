// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Coin.h"

#include "CoinEntry.h"
#include <NiceWCore/NWCoinTypeConfiguration.h>
#include <NiceWCore/NWHRP.h>

#include <map>

// #coin-list# Includes for entry points for coin implementations
#include "Bitcoin/Entry.h"
#include "Ethereum/Entry.h"
// end_of_coin_includes_marker_do_not_modify

using namespace NW;
using namespace std;

// #coin-list# Global coin entry dispatcher entries
Bitcoin::Entry bitcoinDP;
Ethereum::Entry ethereumDP;
// end_of_coin_dipatcher_declarations_marker_do_not_modify

CoinEntry* coinDispatcher(NWCoinType coinType) {
    // switch is preferred instead of a data structure, due to initialization issues
    CoinEntry* entry = nullptr;
    const auto blockchain = NW::blockchain(coinType);
    switch (blockchain) {
        // #coin-list#
        case NWBlockchainBitcoin: entry = &bitcoinDP; break;
        case NWBlockchainEthereum: entry = &ethereumDP; break;
        // end_of_coin_dipatcher_switch_marker_do_not_modify

        default: entry = nullptr; break;
    }
    assert(entry != nullptr);
    return entry;
}

const Derivation CoinInfo::derivationByName(NWDerivation nameIn) const {
    if (nameIn == NWDerivationDefault && derivation.size() > 0) {
        return derivation[0];
    }
    for (auto deriv: derivation) {
        if (deriv.name == nameIn) {
            return deriv;
        }
    }
    return Derivation();
}

bool NW::validateAddress(NWCoinType coin, const std::string& string) {
    auto p2pkh = NW::p2pkhPrefix(coin);
    auto p2sh = NW::p2shPrefix(coin);
    const auto* hrp = stringForHRP(NW::hrp(coin));

    // dispatch
    auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->validateAddress(coin, string, p2pkh, p2sh, hrp);
}

std::string NW::normalizeAddress(NWCoinType coin, const std::string& address) {
    if (!NW::validateAddress(coin, address)) {
        // invalid address, not normalizing
        return "";
    }

    // dispatch
    auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->normalizeAddress(coin, address);
}

std::string NW::deriveAddress(NWCoinType coin, const PrivateKey& privateKey) {
    return NW::deriveAddress(coin, privateKey, NWDerivationDefault);
}

std::string NW::deriveAddress(NWCoinType coin, const PrivateKey& privateKey, NWDerivation derivation) {
    auto keyType = NW::publicKeyType(coin);
    return NW::deriveAddress(coin, privateKey.getPublicKey(keyType), derivation);
}

std::string NW::deriveAddress(NWCoinType coin, const PublicKey& publicKey) {
    return deriveAddress(coin, publicKey, NWDerivationDefault);
}

std::string NW::deriveAddress(NWCoinType coin, const PublicKey& publicKey, NWDerivation derivation) {
    auto p2pkh = NW::p2pkhPrefix(coin);
    const auto* hrp = stringForHRP(NW::hrp(coin));

    // dispatch
    auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->deriveAddress(coin, derivation, publicKey, p2pkh, hrp);
}

Data NW::addressToData(NWCoinType coin, const std::string& address) {
    const auto* dispatcher = coinDispatcher(coin);
    assert(dispatcher != nullptr);
    return dispatcher->addressToData(coin, address);
}

void NW::anyCoinSign(NWCoinType coinType, const Data& dataIn, Data& dataOut) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    dispatcher->sign(coinType, dataIn, dataOut);
}

std::string NW::anySignJSON(NWCoinType coinType, const std::string& json, const Data& key) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->signJSON(coinType, json, key);
}

bool NW::supportsJSONSigning(NWCoinType coinType) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->supportsJSONSigning();
}

void NW::anyCoinPlan(NWCoinType coinType, const Data& dataIn, Data& dataOut) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    dispatcher->plan(coinType, dataIn, dataOut);
}

Data NW::anyCoinPreImageHashes(NWCoinType coinType, const Data& txInputData) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->preImageHashes(coinType, txInputData);
}

void NW::anyCoinCompileWithSignatures(NWCoinType coinType, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& txOutputOut) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    dispatcher->compile(coinType, txInputData, signatures, publicKeys, txOutputOut);
}

Data NW::anyCoinBuildTransactionInput(NWCoinType coinType, const std::string& from, const std::string& to, const uint256_t& amount, const std::string& asset, const std::string& memo, const std::string& chainId) {
    auto* dispatcher = coinDispatcher(coinType);
    assert(dispatcher != nullptr);
    return dispatcher->buildTransactionInput(coinType, from, to, amount, asset, memo, chainId);
}

// Coin info accessors

extern const CoinInfo getCoinInfo(NWCoinType coin); // in generated CoinInfoData.cpp file

NWBlockchain NW::blockchain(NWCoinType coin) {
    return getCoinInfo(coin).blockchain;
}

NWPurpose NW::purpose(NWCoinType coin) {
    return getCoinInfo(coin).purpose;
}

NWCurve NW::curve(NWCoinType coin) {
    return getCoinInfo(coin).curve;
}

NWHDVersion NW::xpubVersion(NWCoinType coin) {
    return getCoinInfo(coin).defaultDerivation().xpubVersion;
}

NWHDVersion NW::xprvVersion(NWCoinType coin) {
    return getCoinInfo(coin).defaultDerivation().xprvVersion;
}

NWHDVersion NW::xpubVersionDerivation(NWCoinType coin, NWDerivation derivation) {
    return getCoinInfo(coin).derivationByName(derivation).xpubVersion;
}

NWHDVersion NW::xprvVersionDerivation(NWCoinType coin, NWDerivation derivation) {
    return getCoinInfo(coin).derivationByName(derivation).xprvVersion;
}

DerivationPath NW::derivationPath(NWCoinType coin) {
    return DerivationPath(getCoinInfo(coin).defaultDerivation().path);
}

DerivationPath NW::derivationPath(NWCoinType coin, NWDerivation derivation) {
    return DerivationPath(getCoinInfo(coin).derivationByName(derivation).path);
}

const char* NW::derivationName(NWCoinType coin, NWDerivation derivation) {
    return getCoinInfo(coin).derivationByName(derivation).nameString;
}

enum NWPublicKeyType NW::publicKeyType(NWCoinType coin) {
    return getCoinInfo(coin).publicKeyType;
}

NW::byte NW::staticPrefix(NWCoinType coin) {
    return getCoinInfo(coin).staticPrefix;
}

NW::byte NW::p2pkhPrefix(NWCoinType coin) {
    return getCoinInfo(coin).p2pkhPrefix;
}

NW::byte NW::p2shPrefix(NWCoinType coin) {
    return getCoinInfo(coin).p2shPrefix;
}

enum NWHRP NW::hrp(NWCoinType coin) {
    return getCoinInfo(coin).hrp;
}

const char* NW::chainId(NWCoinType coin) {
    return getCoinInfo(coin).chainId;
}

Hash::Hasher NW::publicKeyHasher(NWCoinType coin) {
    return getCoinInfo(coin).publicKeyHasher;
}

Hash::Hasher NW::base58Hasher(NWCoinType coin) {
    return getCoinInfo(coin).base58Hasher;
}

Hash::Hasher NW::addressHasher(NWCoinType coin) {
    return getCoinInfo(coin).addressHasher;
}

uint32_t NW::slip44Id(NWCoinType coin) {
    return getCoinInfo(coin).slip44;
}

NWString* _Nullable NWCoinTypeConfigurationGetSymbol(enum NWCoinType coin) {
    return NWStringCreateWithUTF8Bytes(getCoinInfo(coin).symbol);
}

int NWCoinTypeConfigurationGetDecimals(enum NWCoinType coin) {
    return getCoinInfo(coin).decimals;
}

NWString* _Nullable NWCoinTypeConfigurationGetTransactionURL(enum NWCoinType coin, NWString* _Nonnull transactionID) {
    std::string txId = NWStringUTF8Bytes(transactionID);
    std::string url = getCoinInfo(coin).explorerTransactionUrl + txId;
    return NWStringCreateWithUTF8Bytes(url.c_str());
}

NWString* _Nullable NWCoinTypeConfigurationGetAccountURL(enum NWCoinType coin, NWString* _Nonnull accountID) {
    std::string accId = NWStringUTF8Bytes(accountID);
    std::string url = getCoinInfo(coin).explorerAccountUrl + accId;
    return NWStringCreateWithUTF8Bytes(url.c_str());
}

NWString* _Nonnull NWCoinTypeConfigurationGetID(enum NWCoinType coin) {
    return NWStringCreateWithUTF8Bytes(getCoinInfo(coin).id);
}

NWString* _Nonnull NWCoinTypeConfigurationGetName(enum NWCoinType coin) {
    return NWStringCreateWithUTF8Bytes(getCoinInfo(coin).name);
}
