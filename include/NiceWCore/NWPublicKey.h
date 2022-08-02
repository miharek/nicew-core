//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"
#include "NWPublicKeyType.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

static const size_t NWPublicKeyCompressedSize = 33;
static const size_t NWPublicKeyUncompressedSize = 65;

NW_EXPORT_CLASS
struct NWPublicKey;

NW_EXPORT_STATIC_METHOD
struct NWPublicKey *_Nullable NWPublicKeyCreateWithData(NWData *_Nonnull data, enum NWPublicKeyType type);

NW_EXPORT_METHOD
void NWPublicKeyDelete(struct NWPublicKey *_Nonnull pk);

NW_EXPORT_STATIC_METHOD
bool NWPublicKeyIsValid(NWData *_Nonnull data, enum NWPublicKeyType type);

NW_EXPORT_PROPERTY
bool NWPublicKeyIsCompressed(struct NWPublicKey *_Nonnull pk);

NW_EXPORT_PROPERTY
struct NWPublicKey *_Nonnull NWPublicKeyCompressed(struct NWPublicKey *_Nonnull from);

NW_EXPORT_PROPERTY
struct NWPublicKey *_Nonnull NWPublicKeyUncompressed(struct NWPublicKey *_Nonnull from);

NW_EXPORT_PROPERTY
NWData *_Nonnull NWPublicKeyData(struct NWPublicKey *_Nonnull pk);

NW_EXPORT_METHOD
bool NWPublicKeyVerify(struct NWPublicKey *_Nonnull pk, NWData *_Nonnull signature, NWData *_Nonnull message);

NW_EXPORT_METHOD
bool NWPublicKeyVerifyAsDER(struct NWPublicKey *_Nonnull pk, NWData *_Nonnull signature, NWData *_Nonnull message);

/// Verify a Zilliqa schnorr signature with a signature and message.
NW_EXPORT_METHOD
bool NWPublicKeyVerifyZilliqaSchnorr(struct NWPublicKey *_Nonnull pk, NWData *_Nonnull signature, NWData *_Nonnull message);

NW_EXPORT_PROPERTY
enum NWPublicKeyType NWPublicKeyKeyType(struct NWPublicKey *_Nonnull publicKey);

NW_EXPORT_PROPERTY
NWString *_Nonnull NWPublicKeyDescription(struct NWPublicKey *_Nonnull publicKey);

NW_EXPORT_STATIC_METHOD
struct NWPublicKey *_Nullable NWPublicKeyRecover(NWData *_Nonnull signature, NWData *_Nonnull message);

NW_EXTERN_C_END
