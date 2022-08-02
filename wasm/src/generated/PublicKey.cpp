// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "PublicKey.h"

namespace NW::Wasm {
auto WasmPublicKey::isValid(const std::string& data, NWPublicKeyType type) {
    auto dataData = NW::data(data);
    return NWPublicKeyIsValid(&dataData, type);
}
auto WasmPublicKey::recover(const std::string& signature, const std::string& message) {
    auto signatureData = NW::data(signature);
    auto messageData = NW::data(message);
    return new WasmPublicKey(NWPublicKeyRecover(&signatureData, &messageData));
}
auto WasmPublicKey::createWithData(const std::string& data, NWPublicKeyType type) -> WasmPublicKey* {
    auto dataData = NW::data(data);
    NWPublicKey *instance = NWPublicKeyCreateWithData(&dataData, type);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmPublicKey(instance);
}


auto WasmPublicKey::isCompressed() {
    return NWPublicKeyIsCompressed(instance);
}

auto WasmPublicKey::compressed() {
    return new WasmPublicKey(NWPublicKeyCompressed(instance));
}

auto WasmPublicKey::uncompressed() {
    return new WasmPublicKey(NWPublicKeyUncompressed(instance));
}

auto WasmPublicKey::data() {
    return NWDataToVal(NWPublicKeyData(instance));
}

auto WasmPublicKey::keyType() {
    return NWPublicKeyKeyType(instance);
}

auto WasmPublicKey::description() {
    return NWStringToStd(NWPublicKeyDescription(instance));
}


auto WasmPublicKey::verify(const std::string& signature, const std::string& message) {
    auto signatureData = NW::data(signature);
    auto messageData = NW::data(message);
    return NWPublicKeyVerify(instance, &signatureData, &messageData);
}

auto WasmPublicKey::verifyAsDER(const std::string& signature, const std::string& message) {
    auto signatureData = NW::data(signature);
    auto messageData = NW::data(message);
    return NWPublicKeyVerifyAsDER(instance, &signatureData, &messageData);
}

auto WasmPublicKey::verifyZilliqaSchnorr(const std::string& signature, const std::string& message) {
    auto signatureData = NW::data(signature);
    auto messageData = NW::data(message);
    return NWPublicKeyVerifyZilliqaSchnorr(instance, &signatureData, &messageData);
}


EMSCRIPTEN_BINDINGS(Wasm_NWPublicKey) {
    class_<WasmPublicKey>("PublicKey")
          .class_function("createWithData", &WasmPublicKey::createWithData, allow_raw_pointers())
          .class_function("isValid", &WasmPublicKey::isValid, allow_raw_pointers())
          .class_function("recover", &WasmPublicKey::recover, allow_raw_pointers())
          .function("isCompressed", &WasmPublicKey::isCompressed, allow_raw_pointers())
          .function("compressed", &WasmPublicKey::compressed, allow_raw_pointers())
          .function("uncompressed", &WasmPublicKey::uncompressed, allow_raw_pointers())
          .function("data", &WasmPublicKey::data, allow_raw_pointers())
          .function("keyType", &WasmPublicKey::keyType, allow_raw_pointers())
          .function("description", &WasmPublicKey::description, allow_raw_pointers())
          .function("verify", &WasmPublicKey::verify, allow_raw_pointers())
          .function("verifyAsDER", &WasmPublicKey::verifyAsDER, allow_raw_pointers())
          .function("verifyZilliqaSchnorr", &WasmPublicKey::verifyZilliqaSchnorr, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
