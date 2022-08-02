//
// Created by Mihael Rek on 02/08/2022.
//

#include "../PrivateKey.h"
#include "../PublicKey.h"

#include <TrezorCrypto/ecdsa.h>
#include <TrezorCrypto/rand.h>
#include <TrezorCrypto/secp256k1.h>
#include <NiceWCore/NWPrivateKey.h>

#include <exception>

using namespace NW;

struct NWPrivateKey *NWPrivateKeyCreate() {
    Data bytes(PrivateKey::_size);
    random_buffer(bytes.data(), PrivateKey::_size);
    if (!PrivateKey::isValid(bytes)) {
        // Under no circumstance return an invalid private key. We'd rather
        // crash. This also captures cases where the random generator fails
        // since we initialize the array to zeros, which is an invalid private
        // key.
        std::terminate();
    }

    return new NWPrivateKey{ PrivateKey(std::move(bytes)) };
}

struct NWPrivateKey *_Nullable NWPrivateKeyCreateWithData(NWData *_Nonnull data) {
auto dataSize = NWDataSize(data);
Data bytes(dataSize);
NWDataCopyBytes(data, 0, dataSize, bytes.data());
if (!PrivateKey::isValid(bytes)) {
return nullptr;
}
return new NWPrivateKey{ PrivateKey(std::move(bytes)) };
}

struct NWPrivateKey *_Nullable NWPrivateKeyCreateCopy(struct NWPrivateKey *_Nonnull key) {
    return new NWPrivateKey{ PrivateKey(key->impl.bytes) };
}

void NWPrivateKeyDelete(struct NWPrivateKey *_Nonnull pk) {
    if (pk == nullptr)
        return;
    delete pk;
}

bool NWPrivateKeyIsValid(NWData *_Nonnull data, enum NWCurve curve) {
auto dataSize = NWDataSize(data);
std::vector<uint8_t> bytes(dataSize);
NWDataCopyBytes(data, 0, dataSize, bytes.data());
return PrivateKey::isValid(bytes, curve);
}

NWData *NWPrivateKeyData(struct NWPrivateKey *_Nonnull pk) {
    return NWDataCreateWithBytes(pk->impl.bytes.data(), pk->impl.bytes.size());
}

struct NWPublicKey *_Nonnull NWPrivateKeyGetPublicKeyNist256p1(struct NWPrivateKey *_Nonnull pk) {
    return new NWPublicKey{ pk->impl.getPublicKey(NWPublicKeyTypeNIST256p1) };
}

struct NWPublicKey *_Nonnull NWPrivateKeyGetPublicKeySecp256k1(struct NWPrivateKey *_Nonnull pk, bool compressed) {
    if (compressed)  {
        return new NWPublicKey{ pk->impl.getPublicKey(NWPublicKeyTypeSECP256k1) };
    } else {
        return new NWPublicKey{ pk->impl.getPublicKey(NWPublicKeyTypeSECP256k1Extended) };
    }
}

struct NWPublicKey *_Nonnull NWPrivateKeyGetPublicKeyEd25519(struct NWPrivateKey *_Nonnull pk) {
    return new NWPublicKey{ pk->impl.getPublicKey(NWPublicKeyTypeED25519) };
}

struct NWPublicKey *_Nonnull NWPrivateKeyGetPublicKeyEd25519Blake2b(struct NWPrivateKey *_Nonnull pk) {
    return new NWPublicKey{ pk->impl.getPublicKey(NWPublicKeyTypeED25519Blake2b) };
}

struct NWPublicKey *_Nonnull NWPrivateKeyGetPublicKeyEd25519Cardano(struct NWPrivateKey *_Nonnull pk) {
    return new NWPublicKey{ pk->impl.getPublicKey(NWPublicKeyTypeED25519Cardano) };
}

struct NWPublicKey *_Nonnull NWPrivateKeyGetPublicKeyCurve25519(struct NWPrivateKey *_Nonnull pk) {
    return new NWPublicKey{pk->impl.getPublicKey(NWPublicKeyTypeCURVE25519)};
}

NWData *_Nullable NWPrivateKeyGetSharedKey(const struct NWPrivateKey *_Nonnull pk, const struct NWPublicKey *_Nonnull publicKey, enum NWCurve curve) {
    auto result = pk->impl.getSharedKey(publicKey->impl, curve);
    if (result.empty()) {
        return nullptr;
    } else {
        return NWDataCreateWithBytes(result.data(), result.size());
    }
}

NWData *NWPrivateKeySign(struct NWPrivateKey *_Nonnull pk, NWData *_Nonnull digest, enum NWCurve curve) {
    const auto& d = *reinterpret_cast<const Data*>(digest);
    auto result = pk->impl.sign(d, curve);
    if (result.empty()) {
        return nullptr;
    } else {
        return NWDataCreateWithBytes(result.data(), result.size());
    }
}

NWData* NWPrivateKeySignAsDER(struct NWPrivateKey* pk, NWData* digest) {
    auto& d = *reinterpret_cast<const Data*>(digest);
    auto result = pk->impl.signAsDER(d);
    if (result.empty()) {
        return nullptr;
    } else {
        return NWDataCreateWithBytes(result.data(), result.size());
    }
}

NWData *NWPrivateKeySignZilliqaSchnorr(struct NWPrivateKey *_Nonnull pk, NWData *_Nonnull message) {
    const auto& msg = *reinterpret_cast<const Data*>(message);
    auto result = pk->impl.signZilliqa(msg);

    if (result.empty()) {
        return nullptr;
    } else {
        return NWDataCreateWithBytes(result.data(), result.size());
    }
}
