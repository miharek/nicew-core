// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "Base32.h"

namespace NW::Wasm {
auto WasmBase32::decodeWithAlphabet(const std::string& string, const std::string& alphabet) {
    return NWDataToVal(NWBase32DecodeWithAlphabet(&string, &alphabet));
}
auto WasmBase32::decode(const std::string& string) {
    return NWDataToVal(NWBase32Decode(&string));
}
auto WasmBase32::encodeWithAlphabet(const std::string& data, const std::string& alphabet) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWBase32EncodeWithAlphabet(&dataData, &alphabet));
}
auto WasmBase32::encode(const std::string& data) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWBase32Encode(&dataData));
}



EMSCRIPTEN_BINDINGS(Wasm_NWBase32) {
    class_<WasmBase32>("Base32")
          .class_function("decodeWithAlphabet", &WasmBase32::decodeWithAlphabet, allow_raw_pointers())
          .class_function("decode", &WasmBase32::decode, allow_raw_pointers())
          .class_function("encodeWithAlphabet", &WasmBase32::encodeWithAlphabet, allow_raw_pointers())
          .class_function("encode", &WasmBase32::encode, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
