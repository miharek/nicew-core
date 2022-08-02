// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "Base64.h"

namespace NW::Wasm {
auto WasmBase64::decode(const std::string& string) {
    return NWDataToVal(NWBase64Decode(&string));
}
auto WasmBase64::decodeUrl(const std::string& string) {
    return NWDataToVal(NWBase64DecodeUrl(&string));
}
auto WasmBase64::encode(const std::string& data) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWBase64Encode(&dataData));
}
auto WasmBase64::encodeUrl(const std::string& data) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWBase64EncodeUrl(&dataData));
}



EMSCRIPTEN_BINDINGS(Wasm_NWBase64) {
    class_<WasmBase64>("Base64")
          .class_function("decode", &WasmBase64::decode, allow_raw_pointers())
          .class_function("decodeUrl", &WasmBase64::decodeUrl, allow_raw_pointers())
          .class_function("encode", &WasmBase64::encode, allow_raw_pointers())
          .class_function("encodeUrl", &WasmBase64::encodeUrl, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
