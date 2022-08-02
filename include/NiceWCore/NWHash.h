//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWHash {
    uint8_t unused; // C doesn't allow zero-sized struct
};

static const size_t NWHashSHA1Length = 20;
static const size_t NWHashSHA256Length = 32;
static const size_t NWHashSHA512Length = 64;
static const size_t NWHashRipemdLength = 20;

/// Computes the SHA1 of a block of data.
NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA1(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA512(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA512_256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashKeccak256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashKeccak512(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA3_256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA3_512(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashRIPEMD(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashBlake256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashBlake2b(NWData *_Nonnull data, size_t size);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashGroestl512(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA256SHA256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA256RIPEMD(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashSHA3_256RIPEMD(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashBlake256Blake256(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashBlake256RIPEMD(NWData *_Nonnull data);

NW_EXPORT_STATIC_METHOD
NWData *_Nonnull NWHashGroestl512Groestl512(NWData *_Nonnull data);

NW_EXTERN_C_END
