//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWBase32;

/// Decode a Base32 input with the given alphabet
///
/// \param string Encoded base32 input to be decoded
/// \param alphabet Decode with the given alphabet, if empty ALPHABET_RFC4648 is used by default
/// \return The decoded data, can be null.
/// \note ALPHABET_RFC4648 doesn't support padding in the default alphabet
NW_EXPORT_STATIC_METHOD
NWData* _Nullable NWBase32DecodeWithAlphabet(NWString* _Nonnull string, NWString* _Nonnull alphabet);

/// Decode a Base32 input with the default alphabet (ALPHABET_RFC4648)
///
/// \param string Encoded input to be decoded
/// \return The decoded data
/// \note Call NWBase32DecodeWithAlphabet with empty string.
NW_EXPORT_STATIC_METHOD
NWData* _Nullable NWBase32Decode(NWString* _Nonnull string);

/// Encode an input to Base32 with the given alphabet
///
/// \param data Data to be encoded (raw bytes)
/// \param alphabet Encode with the given alphabet, if empty ALPHABET_RFC4648 is used by default
/// \return The encoded data
/// \note ALPHABET_RFC4648 doesn't support padding in the default alphabet
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWBase32EncodeWithAlphabet(NWData *_Nonnull data, NWString* _Nonnull alphabet);

/// Encode an input to Base32 with the default alphabet (ALPHABET_RFC4648)
///
/// \param data Data to be encoded (raw bytes)
/// \return The encoded data
/// \note Call NWBase32EncodeWithAlphabet with empty string.
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWBase32Encode(NWData *_Nonnull data);

NW_EXTERN_C_END