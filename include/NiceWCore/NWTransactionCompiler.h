//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCoinType.h"
#include "NWData.h"
#include "NWDataVector.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

/// Non-core transaction utility methods, like building a transaction using an external signature.
NW_EXPORT_STRUCT
struct NWTransactionCompiler;

/// Build a coin-specific SigningInput protobuf transaction input, from simple transaction parameters
/// - amount: decimal number as string
/// - asset: optional asset name, like "BNB"
/// - memo: optional memo
/// - chainId: optional chainId to override default
NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWTransactionCompilerBuildInput(enum NWCoinType coinType, NWString *_Nonnull from, NWString *_Nonnull to, NWString *_Nonnull amount, NWString *_Nonnull asset, NWString *_Nonnull memo, NWString *_Nonnull chainId);

/// Obtain pre-signing hashes of a transaction. 
/// It will return a proto object named `PreSigningOutput` which will include hash.
/// We provide a default `PreSigningOutput` in TransactionCompiler.proto.
/// For some special coins, such as bitcoin, we will create a custom `PreSigningOutput` object in its proto file.
NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWTransactionCompilerPreImageHashes(enum NWCoinType coinType, NWData *_Nonnull txInputData);

/// Compile a complete transation with one or more external signatures, put together from transaction input and provided public keys and signatures.
/// The signatures must match the hashes returned by NWTransactionCompilerPreImageHashes, in the same order.
/// The publicKeyHash attached to the hashes enable identifying the private key needed for signing the hash.
NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWTransactionCompilerCompileWithSignatures(enum NWCoinType coinType, NWData *_Nonnull txInputData, const struct NWDataVector *_Nonnull signatures, const struct NWDataVector *_Nonnull publicKeys);

NW_EXTERN_C_END
