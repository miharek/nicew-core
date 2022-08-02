//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWData.h"
#include "NWBase.h"
#include "NWAESPaddingMode.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWAES {
    uint8_t unused;
};

/// Encrypts a block of data using AES in Cipher Block Chaining (CBC) mode.
///
/// \param key encryption key, must be 16, 24, or 32 bytes long.
/// \param data data to encrypt.
/// \param iv initialization vector.
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWAESEncryptCBC(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv, enum NWAESPaddingMode mode);

/// Decrypts a block of data using AES in Cipher Block Chaining (CBC) mode.
///
/// \param key decryption key, must be 16, 24, or 32 bytes long.
/// \param data data to decrypt.
/// \param iv initialization vector.
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWAESDecryptCBC(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv, enum NWAESPaddingMode mode);

/// Encrypts a block of data using AES in Counter (CTR) mode.
///
/// \param key encryption key, must be 16, 24, or 32 bytes long.
/// \param data data to encrypt.
/// \param iv initialization vector.
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWAESEncryptCTR(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv);

/// Decrypts a block of data using AES in Counter (CTR) mode.
///
/// \param key decryption key, must be 16, 24, or 32 bytes long.
/// \param data data to decrypt.
/// \param iv initialization vector.
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWAESDecryptCTR(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv);

NW_EXTERN_C_END