//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWString.h"
#include "NWData.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWEthereumAbiValue;

/// Returned data must be deleted (hint: use WRAPD() macro).
/// Encode a type according to Ethereum ABI, into 32 bytes. Values are padded by 0 on the left, unless specified otherwise.

NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeBool(bool value);

NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeInt32(int32_t value);

NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeUInt32(uint32_t value);

/// Encode an int256.  Input value is represented as a 32-byte value
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeInt256(NWData* _Nonnull value);

/// Encode an uint256.  Input value is represented as a 32-byte binary value
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeUInt256(NWData* _Nonnull value);

/// Encode the 20 bytes of an address
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeAddress(NWData* _Nonnull value);

/// Encode a string by encoding its hash
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeString(NWString* _Nonnull value);

/// Encode a number of bytes, up to 32 bytes, padded on the right.  Longer arrays are truncated.
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeBytes(NWData* _Nonnull value);

/// Encode a dynamic number of bytes by encoding its hash
NW_EXPORT_STATIC_METHOD
NWData* _Nonnull NWEthereumAbiValueEncodeBytesDyn(NWData* _Nonnull value);


/// Decodes input data (bytes longer than 32 will be truncated) as uint256
NW_EXPORT_STATIC_METHOD
NWString* _Nonnull NWEthereumAbiValueDecodeUInt256(NWData* _Nonnull input);

/// Decode an arbitrary type, return value as string
NW_EXPORT_STATIC_METHOD
NWString* _Nonnull NWEthereumAbiValueDecodeValue(NWData* _Nonnull input, NWString* _Nonnull type);

/// Decode an array of given simple types.  Return a '\n'-separated string of elements
NW_EXPORT_STATIC_METHOD
NWString* _Nonnull NWEthereumAbiValueDecodeArray(NWData* _Nonnull input, NWString* _Nonnull type);

NW_EXTERN_C_END
