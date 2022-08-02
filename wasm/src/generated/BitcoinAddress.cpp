// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "BitcoinAddress.h"

namespace NW::Wasm {
auto WasmBitcoinAddress::equal(WasmBitcoinAddress* lhs, WasmBitcoinAddress* rhs) {
    return NWBitcoinAddressEqual(lhs->instance, rhs->instance);
}
auto WasmBitcoinAddress::isValid(const std::string& data) {
    auto dataData = NW::data(data);
    return NWBitcoinAddressIsValid(&dataData);
}
auto WasmBitcoinAddress::isValidString(const std::string& string) {
    return NWBitcoinAddressIsValidString(&string);
}
auto WasmBitcoinAddress::createWithString(const std::string& string) -> WasmBitcoinAddress* {
    NWBitcoinAddress *instance = NWBitcoinAddressCreateWithString(&string);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmBitcoinAddress(instance);
}

auto WasmBitcoinAddress::createWithData(const std::string& data) -> WasmBitcoinAddress* {
    auto dataData = NW::data(data);
    NWBitcoinAddress *instance = NWBitcoinAddressCreateWithData(&dataData);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmBitcoinAddress(instance);
}

auto WasmBitcoinAddress::createWithPublicKey(WasmPublicKey* publicKey, uint8_t prefix) -> WasmBitcoinAddress* {
    NWBitcoinAddress *instance = NWBitcoinAddressCreateWithPublicKey(publicKey->instance, prefix);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmBitcoinAddress(instance);
}


auto WasmBitcoinAddress::description() {
    return NWStringToStd(NWBitcoinAddressDescription(instance));
}

auto WasmBitcoinAddress::prefix() {
    return NWBitcoinAddressPrefix(instance);
}

auto WasmBitcoinAddress::keyhash() {
    return NWDataToVal(NWBitcoinAddressKeyhash(instance));
}



EMSCRIPTEN_BINDINGS(Wasm_NWBitcoinAddress) {
    class_<WasmBitcoinAddress>("BitcoinAddress")
          .class_function("equal", &WasmBitcoinAddress::equal, allow_raw_pointers())
          .class_function("isValid", &WasmBitcoinAddress::isValid, allow_raw_pointers())
          .class_function("isValidString", &WasmBitcoinAddress::isValidString, allow_raw_pointers())
          .class_function("createWithString", &WasmBitcoinAddress::createWithString, allow_raw_pointers())
          .class_function("createWithData", &WasmBitcoinAddress::createWithData, allow_raw_pointers())
          .class_function("createWithPublicKey", &WasmBitcoinAddress::createWithPublicKey, allow_raw_pointers())
          .function("description", &WasmBitcoinAddress::description, allow_raw_pointers())
          .function("prefix", &WasmBitcoinAddress::prefix, allow_raw_pointers())
          .function("keyhash", &WasmBitcoinAddress::keyhash, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
