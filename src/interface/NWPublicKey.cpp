//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWPublicKey.h>

#include "../HexCoding.h"
#include "../PublicKey.h"

#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/secp256k1.h>

using NW::PublicKey;

struct NWPublicKey *_Nullable NWPublicKeyCreateWithData(NWData *_Nonnull data, enum NWPublicKeyType type) {
auto& d = *reinterpret_cast<const NW::Data *>(data);
if (!PublicKey::isValid(d, type)) {
return nullptr;
}

return new NWPublicKey{ PublicKey(d, type) };
}

void NWPublicKeyDelete(struct NWPublicKey *_Nonnull pk) {
    delete pk;
}

bool NWPublicKeyIsValid(NWData *_Nonnull data, enum NWPublicKeyType type) {
auto& d = *reinterpret_cast<const NW::Data *>(data);
return PublicKey::isValid(d, type);
}

bool NWPublicKeyIsCompressed(struct NWPublicKey *_Nonnull pk) {
    return pk->impl.isCompressed();
}

NWData *NWPublicKeyData(struct NWPublicKey *_Nonnull pk) {
    return NWDataCreateWithBytes(pk->impl.bytes.data(), pk->impl.bytes.size());
}

struct NWPublicKey *_Nonnull NWPublicKeyCompressed(struct NWPublicKey *_Nonnull pk) {
    return new NWPublicKey{ pk->impl.compressed() };
}

struct NWPublicKey *_Nonnull NWPublicKeyUncompressed(struct NWPublicKey *_Nonnull pk) {
    return new NWPublicKey{ pk->impl.extended() };
}

bool NWPublicKeyVerify(struct NWPublicKey *_Nonnull pk, NWData *_Nonnull signature, NWData *message) {
    const auto& s = *reinterpret_cast<const NW::Data *>(signature);
    const auto& m = *reinterpret_cast<const NW::Data *>(message);
    return pk->impl.verify(s, m);
}

bool NWPublicKeyVerifyAsDER(struct NWPublicKey *_Nonnull pk, NWData *_Nonnull signature, NWData *message) {
    const auto& s = *reinterpret_cast<const NW::Data *>(signature);
    const auto& m = *reinterpret_cast<const NW::Data *>(message);
    return pk->impl.verifyAsDER(s, m);
}

bool NWPublicKeyVerifyZilliqaSchnorr(struct NWPublicKey *_Nonnull pk, NWData *_Nonnull signature, NWData *_Nonnull message) {
    const auto& s = *reinterpret_cast<const NW::Data *>(signature);
    const auto& m = *reinterpret_cast<const NW::Data *>(message);
    return pk->impl.verifyZilliqa(s, m);
}

enum NWPublicKeyType NWPublicKeyKeyType(struct NWPublicKey *_Nonnull publicKey) {
    return publicKey->impl.type;
}

NWString *_Nonnull NWPublicKeyDescription(struct NWPublicKey *_Nonnull publicKey) {
    const auto string = NW::hex(publicKey->impl.bytes);
    return NWStringCreateWithUTF8Bytes(string.c_str());
}

struct NWPublicKey *_Nullable NWPublicKeyRecover(NWData *_Nonnull signature, NWData *_Nonnull message) {
try {
const PublicKey publicKey = PublicKey::recover(*((NW::Data*)signature), *((NW::Data*)message));
return new NWPublicKey{ publicKey };
} catch (...) {
return nullptr;
}
}
