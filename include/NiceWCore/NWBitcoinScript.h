//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"
#include "NWPublicKey.h"
#include "NWCoinType.h"
#include "NWBitcoinSigHashType.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_CLASS
struct NWBitcoinScript;

/// Creates an empty script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptCreate();

/// Creates a script from a raw data representation.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptCreateWithData(NWData *_Nonnull data);
struct NWBitcoinScript *_Nonnull NWBitcoinScriptCreateWithBytes(uint8_t *_Nonnull bytes, size_t size);

/// Creates a script by copying an existring script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptCreateCopy(const struct NWBitcoinScript *_Nonnull script);

NW_EXPORT_METHOD
void NWBitcoinScriptDelete(struct NWBitcoinScript *_Nonnull script);

NW_EXPORT_PROPERTY
size_t NWBitcoinScriptSize(const struct NWBitcoinScript *_Nonnull script);

NW_EXPORT_PROPERTY
NWData *_Nonnull NWBitcoinScriptData(const struct NWBitcoinScript *_Nonnull script);

NW_EXPORT_PROPERTY
NWData *_Nonnull NWBitcoinScriptScriptHash(const struct NWBitcoinScript *_Nonnull script);

/// Determines whether this is a pay-to-script-hash (P2SH) script.
NW_EXPORT_PROPERTY
bool NWBitcoinScriptIsPayToScriptHash(const struct NWBitcoinScript *_Nonnull script);

/// Determines whether this is a pay-to-witness-script-hash (P2WSH) script.
NW_EXPORT_PROPERTY
bool NWBitcoinScriptIsPayToWitnessScriptHash(const struct NWBitcoinScript *_Nonnull script);

/// Determines whether this is a pay-to-witness-public-key-hash (P2WPKH) script.
NW_EXPORT_PROPERTY
bool NWBitcoinScriptIsPayToWitnessPublicKeyHash(const struct NWBitcoinScript *_Nonnull script);

/// Determines whether this is a witness programm script.
NW_EXPORT_PROPERTY
bool NWBitcoinScriptIsWitnessProgram(const struct NWBitcoinScript *_Nonnull script);

NW_EXPORT_STATIC_METHOD
bool NWBitcoinScriptEqual(const struct NWBitcoinScript *_Nonnull lhs, const struct NWBitcoinScript *_Nonnull rhs);

/// Matches the script to a pay-to-public-key (P2PK) script.
///
/// - Returns: the public key.
NW_EXPORT_METHOD
NWData *_Nullable NWBitcoinScriptMatchPayToPubkey(const struct NWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-public-key-hash (P2PKH).
///
/// - Returns: the key hash.
NW_EXPORT_METHOD
NWData *_Nullable NWBitcoinScriptMatchPayToPubkeyHash(const struct NWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-script-hash (P2SH).
///
/// - Returns: the script hash.
NW_EXPORT_METHOD
NWData *_Nullable NWBitcoinScriptMatchPayToScriptHash(const struct NWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-witness-public-key-hash (P2WPKH).
///
/// - Returns: the key hash.
NW_EXPORT_METHOD
NWData *_Nullable NWBitcoinScriptMatchPayToWitnessPublicKeyHash(const struct NWBitcoinScript *_Nonnull script);

/// Matches the script to a pay-to-witness-script-hash (P2WSH).
///
/// - Returns: the script hash, a SHA256 of the witness script.
NW_EXPORT_METHOD
NWData *_Nullable NWBitcoinScriptMatchPayToWitnessScriptHash(const struct NWBitcoinScript *_Nonnull script);

/// Encodes the script.
NW_EXPORT_METHOD
NWData *_Nonnull NWBitcoinScriptEncode(const struct NWBitcoinScript *_Nonnull script);

/// Builds a standard 'pay to public key' script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptBuildPayToPublicKey(NWData *_Nonnull pubkey);

/// Builds a standard 'pay to public key hash' script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptBuildPayToPublicKeyHash(NWData *_Nonnull hash);

/// Builds a standard 'pay to script hash' script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptBuildPayToScriptHash(NWData *_Nonnull scriptHash);

/// Builds a pay-to-witness-public-key-hash (P2WPKH) script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptBuildPayToWitnessPubkeyHash(NWData *_Nonnull hash);

/// Builds a pay-to-witness-script-hash (P2WSH) script.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptBuildPayToWitnessScriptHash(NWData *_Nonnull scriptHash);

/// Builds a appropriate lock script for the given address.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinScript *_Nonnull NWBitcoinScriptLockScriptForAddress(NWString *_Nonnull address, enum NWCoinType coin);

// Return the default HashType for the given coin, such as NWBitcoinSigHashTypeAll.
NW_EXPORT_STATIC_METHOD
uint32_t NWBitcoinScriptHashTypeForCoin(enum NWCoinType coinType);

NW_EXTERN_C_END