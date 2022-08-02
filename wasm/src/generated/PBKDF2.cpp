// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "PBKDF2.h"

namespace NW::Wasm {
auto WasmPBKDF2::hmacSha256(const std::string& password, const std::string& salt, uint32_t iterations, uint32_t dkLen) {
    auto passwordData = NW::data(password);
    auto saltData = NW::data(salt);
    return NWDataToVal(NWPBKDF2HmacSha256(&passwordData, &saltData, iterations, dkLen));
}
auto WasmPBKDF2::hmacSha512(const std::string& password, const std::string& salt, uint32_t iterations, uint32_t dkLen) {
    auto passwordData = NW::data(password);
    auto saltData = NW::data(salt);
    return NWDataToVal(NWPBKDF2HmacSha512(&passwordData, &saltData, iterations, dkLen));
}



EMSCRIPTEN_BINDINGS(Wasm_NWPBKDF2) {
    class_<WasmPBKDF2>("PBKDF2")
          .class_function("hmacSha256", &WasmPBKDF2::hmacSha256, allow_raw_pointers())
          .class_function("hmacSha512", &WasmPBKDF2::hmacSha512, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
