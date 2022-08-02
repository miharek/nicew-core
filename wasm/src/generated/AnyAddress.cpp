// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "AnyAddress.h"

namespace NW::Wasm {
auto WasmAnyAddress::equal(WasmAnyAddress* lhs, WasmAnyAddress* rhs) {
    return NWAnyAddressEqual(lhs->instance, rhs->instance);
}
auto WasmAnyAddress::isValid(const std::string& string, NWCoinType coin) {
    return NWAnyAddressIsValid(&string, coin);
}
auto WasmAnyAddress::createWithString(const std::string& string, NWCoinType coin) -> WasmAnyAddress* {
    NWAnyAddress *instance = NWAnyAddressCreateWithString(&string, coin);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmAnyAddress(instance);
}

auto WasmAnyAddress::createWithPublicKey(WasmPublicKey* publicKey, NWCoinType coin) -> WasmAnyAddress* {
    NWAnyAddress *instance = NWAnyAddressCreateWithPublicKey(publicKey->instance, coin);
    return new WasmAnyAddress(instance);
}


auto WasmAnyAddress::description() {
    return NWStringToStd(NWAnyAddressDescription(instance));
}

auto WasmAnyAddress::coin() {
    return NWAnyAddressCoin(instance);
}

auto WasmAnyAddress::data() {
    return NWDataToVal(NWAnyAddressData(instance));
}



EMSCRIPTEN_BINDINGS(Wasm_NWAnyAddress) {
    class_<WasmAnyAddress>("AnyAddress")
          .class_function("equal", &WasmAnyAddress::equal, allow_raw_pointers())
          .class_function("isValid", &WasmAnyAddress::isValid, allow_raw_pointers())
          .class_function("createWithString", &WasmAnyAddress::createWithString, allow_raw_pointers())
          .class_function("createWithPublicKey", &WasmAnyAddress::createWithPublicKey, allow_raw_pointers())
          .function("description", &WasmAnyAddress::description, allow_raw_pointers())
          .function("coin", &WasmAnyAddress::coin, allow_raw_pointers())
          .function("data", &WasmAnyAddress::data, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
