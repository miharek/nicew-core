//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCurve.h"
#include "NWData.h"
#include "NWPublicKey.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_CLASS
struct NWPrivateKey;

static const size_t NWPrivateKeySize = 32;

NW_EXPORT_STATIC_METHOD
struct NWPrivateKey* _Nonnull NWPrivateKeyCreate(void);

NW_EXPORT_STATIC_METHOD
struct NWPrivateKey* _Nullable NWPrivateKeyCreateWithData(NWData* _Nonnull data);

NW_EXPORT_STATIC_METHOD
struct NWPrivateKey* _Nullable NWPrivateKeyCreateCopy(struct NWPrivateKey* _Nonnull key);

NW_EXPORT_METHOD
void NWPrivateKeyDelete(struct NWPrivateKey* _Nonnull pk);

NW_EXPORT_STATIC_METHOD
bool NWPrivateKeyIsValid(NWData* _Nonnull data, enum NWCurve curve);

NW_EXPORT_PROPERTY
NWData* _Nonnull NWPrivateKeyData(struct NWPrivateKey* _Nonnull pk);

/// Returns the public key associated with this private key.
NW_EXPORT_METHOD
struct NWPublicKey* _Nonnull NWPrivateKeyGetPublicKeySecp256k1(struct NWPrivateKey* _Nonnull pk, bool compressed);

/// Returns the public key associated with this private key.
NW_EXPORT_METHOD
struct NWPublicKey* _Nonnull NWPrivateKeyGetPublicKeyNist256p1(struct NWPrivateKey* _Nonnull pk);

/// Returns the public key associated with this private key.
NW_EXPORT_METHOD
struct NWPublicKey* _Nonnull NWPrivateKeyGetPublicKeyEd25519(struct NWPrivateKey* _Nonnull pk);

/// Returns the public key associated with this private key.
NW_EXPORT_METHOD
struct NWPublicKey* _Nonnull NWPrivateKeyGetPublicKeyEd25519Blake2b(struct NWPrivateKey* _Nonnull pk);

/// Returns the Cardano style public key associated with this private key.
NW_EXPORT_METHOD
struct NWPublicKey* _Nonnull NWPrivateKeyGetPublicKeyEd25519Cardano(struct NWPrivateKey* _Nonnull pk);

/// Returns the public key associated with this private key.
NW_EXPORT_METHOD
struct NWPublicKey* _Nonnull NWPrivateKeyGetPublicKeyCurve25519(struct NWPrivateKey* _Nonnull pk);

/// Computes an EC Diffie-Hellman secret in constant time
/// Supported curves: secp256k1
NW_EXPORT_METHOD
NWData* _Nullable NWPrivateKeyGetSharedKey(const struct NWPrivateKey* _Nonnull pk, const struct NWPublicKey* _Nonnull publicKey, enum NWCurve curve);

/// Signs a digest using ECDSA and given curve.
NW_EXPORT_METHOD
NWData* _Nullable NWPrivateKeySign(struct NWPrivateKey* _Nonnull pk, NWData* _Nonnull digest, enum NWCurve curve);

/// Signs a digest using ECDSA. The result is encoded with DER.
NW_EXPORT_METHOD
NWData* _Nullable NWPrivateKeySignAsDER(struct NWPrivateKey* _Nonnull pk, NWData* _Nonnull digest);

/// Signs a digest using ECDSA and Zilliqa schnorr signature scheme.
NW_EXPORT_METHOD
NWData* _Nullable NWPrivateKeySignZilliqaSchnorr(struct NWPrivateKey* _Nonnull pk, NWData* _Nonnull message);

NW_EXTERN_C_END
