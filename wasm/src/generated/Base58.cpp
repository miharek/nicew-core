// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "Base58.h"

namespace NW::Wasm {
auto WasmBase58::encode(const std::string& data) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWBase58Encode(&dataData));
}
auto WasmBase58::encodeNoCheck(const std::string& data) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWBase58EncodeNoCheck(&dataData));
}
auto WasmBase58::decode(const std::string& string) {
    return NWDataToVal(NWBase58Decode(&string));
}
auto WasmBase58::decodeNoCheck(const std::string& string) {
    return NWDataToVal(NWBase58DecodeNoCheck(&string));
}



EMSCRIPTEN_BINDINGS(Wasm_NWBase58) {
    class_<WasmBase58>("Base58")
          .class_function("encode", &WasmBase58::encode, allow_raw_pointers())
          .class_function("encodeNoCheck", &WasmBase58::encodeNoCheck, allow_raw_pointers())
          .class_function("decode", &WasmBase58::decode, allow_raw_pointers())
          .class_function("decodeNoCheck", &WasmBase58::decodeNoCheck, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
