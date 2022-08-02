// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "PrivateKey.h"

namespace NW::Wasm {
auto WasmPrivateKey::isValid(const std::string& data, NWCurve curve) {
    auto dataData = NW::data(data);
    return NWPrivateKeyIsValid(&dataData, curve);
}
auto WasmPrivateKey::create() -> WasmPrivateKey* {
    NWPrivateKey *instance = NWPrivateKeyCreate();
    return new WasmPrivateKey(instance);
}

auto WasmPrivateKey::createWithData(const std::string& data) -> WasmPrivateKey* {
    auto dataData = NW::data(data);
    NWPrivateKey *instance = NWPrivateKeyCreateWithData(&dataData);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmPrivateKey(instance);
}

auto WasmPrivateKey::createCopy(WasmPrivateKey* key) -> WasmPrivateKey* {
    NWPrivateKey *instance = NWPrivateKeyCreateCopy(key->instance);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmPrivateKey(instance);
}


auto WasmPrivateKey::data() {
    return NWDataToVal(NWPrivateKeyData(instance));
}


auto WasmPrivateKey::getPublicKeySecp256k1(bool compressed) {
    return new WasmPublicKey(NWPrivateKeyGetPublicKeySecp256k1(instance, compressed));
}

auto WasmPrivateKey::getPublicKeyNist256p1() {
    return new WasmPublicKey(NWPrivateKeyGetPublicKeyNist256p1(instance));
}

auto WasmPrivateKey::getPublicKeyEd25519() {
    return new WasmPublicKey(NWPrivateKeyGetPublicKeyEd25519(instance));
}

auto WasmPrivateKey::getPublicKeyEd25519Blake2b() {
    return new WasmPublicKey(NWPrivateKeyGetPublicKeyEd25519Blake2b(instance));
}

auto WasmPrivateKey::getPublicKeyEd25519Cardano() {
    return new WasmPublicKey(NWPrivateKeyGetPublicKeyEd25519Cardano(instance));
}

auto WasmPrivateKey::getPublicKeyCurve25519() {
    return new WasmPublicKey(NWPrivateKeyGetPublicKeyCurve25519(instance));
}

auto WasmPrivateKey::getSharedKey(WasmPublicKey* publicKey, NWCurve curve) {
    return NWDataToVal(NWPrivateKeyGetSharedKey(instance, publicKey->instance, curve));
}

auto WasmPrivateKey::sign(const std::string& digest, NWCurve curve) {
    auto digestData = NW::data(digest);
    return NWDataToVal(NWPrivateKeySign(instance, &digestData, curve));
}

auto WasmPrivateKey::signAsDER(const std::string& digest) {
    auto digestData = NW::data(digest);
    return NWDataToVal(NWPrivateKeySignAsDER(instance, &digestData));
}

auto WasmPrivateKey::signZilliqaSchnorr(const std::string& message) {
    auto messageData = NW::data(message);
    return NWDataToVal(NWPrivateKeySignZilliqaSchnorr(instance, &messageData));
}


EMSCRIPTEN_BINDINGS(Wasm_NWPrivateKey) {
    class_<WasmPrivateKey>("PrivateKey")
          .class_function("create", &WasmPrivateKey::create, allow_raw_pointers())
          .class_function("createWithData", &WasmPrivateKey::createWithData, allow_raw_pointers())
          .class_function("createCopy", &WasmPrivateKey::createCopy, allow_raw_pointers())
          .class_function("isValid", &WasmPrivateKey::isValid, allow_raw_pointers())
          .function("data", &WasmPrivateKey::data, allow_raw_pointers())
          .function("getPublicKeySecp256k1", &WasmPrivateKey::getPublicKeySecp256k1, allow_raw_pointers())
          .function("getPublicKeyNist256p1", &WasmPrivateKey::getPublicKeyNist256p1, allow_raw_pointers())
          .function("getPublicKeyEd25519", &WasmPrivateKey::getPublicKeyEd25519, allow_raw_pointers())
          .function("getPublicKeyEd25519Blake2b", &WasmPrivateKey::getPublicKeyEd25519Blake2b, allow_raw_pointers())
          .function("getPublicKeyEd25519Cardano", &WasmPrivateKey::getPublicKeyEd25519Cardano, allow_raw_pointers())
          .function("getPublicKeyCurve25519", &WasmPrivateKey::getPublicKeyCurve25519, allow_raw_pointers())
          .function("getSharedKey", &WasmPrivateKey::getSharedKey, allow_raw_pointers())
          .function("sign", &WasmPrivateKey::sign, allow_raw_pointers())
          .function("signAsDER", &WasmPrivateKey::signAsDER, allow_raw_pointers())
          .function("signZilliqaSchnorr", &WasmPrivateKey::signZilliqaSchnorr, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
