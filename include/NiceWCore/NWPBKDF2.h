//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWPBKDF2;

/// Derives a key from a password and a salt using PBKDF2 + Sha256.
///
/// \param password is the master password from which a derived key is generated
/// \param salt is a sequence of bits, known as a cryptographic salt
/// \param iterations is the number of iterations desired
/// \param dkLen is the desired bit-length of the derived key
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWPBKDF2HmacSha256(NWData *_Nonnull password, NWData *_Nonnull salt, uint32_t iterations, uint32_t dkLen);

/// Derives a key from a password and a salt using PBKDF2 + Sha512.
///
/// \param password is the master password from which a derived key is generated
/// \param salt is a sequence of bits, known as a cryptographic salt
/// \param iterations is the number of iterations desired
/// \param dkLen is the desired bit-length of the derived key
NW_EXPORT_STATIC_METHOD
NWData *_Nullable NWPBKDF2HmacSha512(NWData *_Nonnull password, NWData *_Nonnull salt, uint32_t iterations, uint32_t dkLen);

NW_EXTERN_C_END
