//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWString.h"
#include "NWData.h"

// Wrapper class for Ethereum ABI encoding & decoding.

NW_EXTERN_C_BEGIN

struct NWEthereumAbiFunction;

NW_EXPORT_STRUCT
struct NWEthereumAbi;

/// Encode function to Eth ABI binary
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiEncode(struct NWEthereumAbiFunction* _Nonnull fn);

/// Decode function output from Eth ABI binary, fill output parameters
NW_EXPORT_STATIC_METHOD
bool NWEthereumAbiDecodeOutput(struct NWEthereumAbiFunction* _Nonnull fn, NWData* _Nonnull encoded);

/// Decode function call data to human readable json format, according to input abi json
NW_EXPORT_STATIC_METHOD
NWString* _Nullable NWEthereumAbiDecodeCall(NWData* _Nonnull data, NWString* _Nonnull abi);

/// Compute the hash of a struct, used for signing, according to EIP712 ("v4").
/// Input is a Json object (as string), with following fields:
/// - types: map of used struct types (see makeTypes())
/// - primaryType: the type of the message (string)
/// - domain: EIP712 domain specifier values
/// - message: the message (object).
/// Throws on error.
/// Example input:
///  R"({
///     "types": {
///         "EIP712Domain": [
///             {"name": "name", "type": "string"},
///             {"name": "version", "type": "string"},
///             {"name": "chainId", "type": "uint256"},
///             {"name": "verifyingContract", "type": "address"}
///         ],
///         "Person": [
///             {"name": "name", "type": "string"},
///             {"name": "wallet", "type": "address"}
///         ]
///     },
///     "primaryType": "Person",
///     "domain": {
///         "name": "Ether Person",
///         "version": "1",
///         "chainId": 1,
///         "verifyingContract": "0xCcCCccccCCCCcCCCCCCcCcCccCcCCCcCcccccccC"
///     },
///     "message": {
///         "name": "Cow",
///         "wallet": "CD2a3d9F938E13CD947Ec05AbC7FE734Df8DD826"
///     }
///  })");
/// On error, empty Data is returned.
/// Returned data must be deleted (hint: use WRAPD() macro).
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiEncodeTyped(NWString* _Nonnull messageJson);

NW_EXTERN_C_END
