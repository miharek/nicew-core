//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWBase64;


/// Decode a Base64 input with the default alphabet (RFC4648 with '+', '/')
///
/// \param string Encoded input to be decoded
/// \return The decoded data
NW_EXPORT_STATIC_METHOD
NWData* _Nullable NWBase64Decode(NWString* _Nonnull string);

/// Decode a Base64 input with the alphabet safe for URL-s and filenames (RFC4648 with '-', '_')
///
/// \param string Encoded base64 input to be decoded
/// \return The decoded data
NW_EXPORT_STATIC_METHOD
NWData* _Nullable NWBase64DecodeUrl(NWString* _Nonnull string);

/// Encode an input to Base64 with the default alphabet (RFC4648 with '+', '/')
///
/// \param data Data to be encoded (raw bytes)
/// \return The encoded data
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWBase64Encode(NWData *_Nonnull data);

/// Encode an input to Base64 with the alphabet safe for URL-s and filenames (RFC4648 with '-', '_')
///
/// \param data Data to be encoded (raw bytes)
/// \return The encoded data
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWBase64EncodeUrl(NWData *_Nonnull data);

NW_EXTERN_C_END