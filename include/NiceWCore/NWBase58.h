//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWBase58;

/// Encodes data as a Base58 string, including the checksum.
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWBase58Encode(NWData *_Nonnull data);

/// Encodes data as a Base58 string, not including the checksum.
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWBase58EncodeNoCheck(NWData *_Nonnull data);

/// Decodes a Base58 string checking the checksum.
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWBase58Decode(NWString *_Nonnull string);

/// Decodes a Base58 string with no checksum.
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWBase58DecodeNoCheck(NWString *_Nonnull string);

NW_EXTERN_C_END
