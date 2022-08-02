// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Data.h"
#include "Hash.h"
#include "DerivationPath.h"
#include "PrivateKey.h"
#include "PublicKey.h"
#include "uint256.h"
#include "CoinEntry.h"

#include <NiceWCore/NWBlockchain.h>
#include <NiceWCore/NWCoinType.h>
#include <NiceWCore/NWCurve.h>
#include <NiceWCore/NWHDVersion.h>
#include <NiceWCore/NWPurpose.h>
#include <NiceWCore/NWDerivation.h>

#include <string>
#include <vector>

namespace NW {

// Return the set of supported coin types.
std::vector<NWCoinType> getCoinTypes();

/// Validates an address for a particular coin.
bool validateAddress(NWCoinType coin, const std::string& address);

/// Validates and normalizes an address for a particular coin.
std::string normalizeAddress(NWCoinType coin, const std::string& address);

/// Returns the blockchain for a coin type.
NWBlockchain blockchain(NWCoinType coin);

/// Returns the purpose for a coin type.
NWPurpose purpose(NWCoinType coin);

/// Returns the curve that should be used for a coin type.
NWCurve curve(NWCoinType coin);

/// Returns the default xpub HD version that should be used for a coin type.
NWHDVersion xpubVersion(NWCoinType coin);

/// Returns the default xprv HD version that should be used for a coin type.
NWHDVersion xprvVersion(NWCoinType coin);

/// Returns the xpub HD version for a NWDerivation.
NWHDVersion xpubVersionDerivation(NWCoinType coin, NWDerivation derivation);

/// Returns the xprv HD version for a NWDerivation.
NWHDVersion xprvVersionDerivation(NWCoinType coin, NWDerivation derivation);

/// Returns the default derivation path for a particular coin.
DerivationPath derivationPath(NWCoinType coin);

/// Returns an alternative derivation path for a particular coin, NWDerivationDefault for default.
DerivationPath derivationPath(NWCoinType coin, NWDerivation derivation);

/// Returns the string name of a derivation for a particular coin.
const char* derivationName(NWCoinType coin, NWDerivation derivation);

/// Returns the public key type for a particular coin.
enum NWPublicKeyType publicKeyType(NWCoinType coin);

/// Derives the address for a particular coin from the private key.
std::string deriveAddress(NWCoinType coin, const PrivateKey& privateKey);

/// Derives the address for a particular coin from the private key, with given derivation.
std::string deriveAddress(NWCoinType coin, const PrivateKey& privateKey, NWDerivation derivation);

/// Derives the address for a particular coin from the public key.
std::string deriveAddress(NWCoinType coin, const PublicKey& publicKey);

/// Derives the address for a particular coin from the public key, with given derivation.
std::string deriveAddress(NWCoinType coin, const PublicKey& publicKey, NWDerivation derivation);

/// Returns the binary representation of a string address
Data addressToData(NWCoinType coin, const std::string& address);

/// Hasher for deriving the extended public key
Hash::Hasher publicKeyHasher(NWCoinType coin);

/// Hasher to use for base 58 checksums in keys (extended private, public)
Hash::Hasher base58Hasher(NWCoinType coin);

/// Hasher used inside address generation (hash of public key)
Hash::Hasher addressHasher(NWCoinType coin);

/// Returns static prefix for a coin type.
byte staticPrefix(NWCoinType coin);

/// Returns P2PKH prefix for a coin type.
byte p2pkhPrefix(NWCoinType coin);

/// Returns P2SH prefix for a coin type.
byte p2shPrefix(NWCoinType coin);

/// Returns human readable part for a coin type.
enum NWHRP hrp(NWCoinType coin);

/// Returns chain ID.
const char* chainId(NWCoinType coin);

// Note: use output parameter to avoid unneeded copies
void anyCoinSign(NWCoinType coinType, const Data& dataIn, Data& dataOut);

uint32_t slip44Id(NWCoinType coin);

std::string anySignJSON(NWCoinType coinType, const std::string& json, const Data& key);

bool supportsJSONSigning(NWCoinType coinType);

void anyCoinPlan(NWCoinType coinType, const Data& dataIn, Data& dataOut);

Data anyCoinPreImageHashes(NWCoinType coinType, const Data& txInputData);

void anyCoinCompileWithSignatures(NWCoinType coinType, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& txOutputOut);

Data anyCoinBuildTransactionInput(NWCoinType coinType, const std::string& from, const std::string& to, const uint256_t& amount, const std::string& asset, const std::string& memo, const std::string& chainId);

// Describes a derivation: path + optional format + optional name
struct Derivation {
    NWDerivation name = NWDerivationDefault;
    const char* path = "";
    const char* nameString = "";
    NWHDVersion xpubVersion = NWHDVersionNone;
    NWHDVersion xprvVersion = NWHDVersionNone;
};

// Contains only simple types.
struct CoinInfo {
    const char* id;
    const char* name;
    NWBlockchain blockchain;
    NWPurpose purpose;
    NWCurve curve;
    std::vector<Derivation> derivation;
    NWPublicKeyType publicKeyType;
    byte staticPrefix;
    byte p2pkhPrefix;
    byte p2shPrefix;
    NWHRP hrp;
    const char* chainId;
    Hash::Hasher publicKeyHasher;
    Hash::Hasher base58Hasher;
    Hash::Hasher addressHasher;
    const char* symbol;
    int decimals;
    const char* explorerTransactionUrl;
    const char* explorerAccountUrl;
    uint32_t slip44;

    // returns default derivation
    const Derivation defaultDerivation() const {
        return (derivation.size() > 0) ? derivation[0] : Derivation();
    }
    const Derivation derivationByName(NWDerivation name) const;
};

} // namespace NW
