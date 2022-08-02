// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "AES.h"

namespace NW::Wasm {
auto WasmAES::encryptCBC(const std::string& key, const std::string& data, const std::string& iv, NWAESPaddingMode mode) {
    auto keyData = NW::data(key);
    auto dataData = NW::data(data);
    auto ivData = NW::data(iv);
    return NWDataToVal(NWAESEncryptCBC(&keyData, &dataData, &ivData, mode));
}
auto WasmAES::decryptCBC(const std::string& key, const std::string& data, const std::string& iv, NWAESPaddingMode mode) {
    auto keyData = NW::data(key);
    auto dataData = NW::data(data);
    auto ivData = NW::data(iv);
    return NWDataToVal(NWAESDecryptCBC(&keyData, &dataData, &ivData, mode));
}
auto WasmAES::encryptCTR(const std::string& key, const std::string& data, const std::string& iv) {
    auto keyData = NW::data(key);
    auto dataData = NW::data(data);
    auto ivData = NW::data(iv);
    return NWDataToVal(NWAESEncryptCTR(&keyData, &dataData, &ivData));
}
auto WasmAES::decryptCTR(const std::string& key, const std::string& data, const std::string& iv) {
    auto keyData = NW::data(key);
    auto dataData = NW::data(data);
    auto ivData = NW::data(iv);
    return NWDataToVal(NWAESDecryptCTR(&keyData, &dataData, &ivData));
}



EMSCRIPTEN_BINDINGS(Wasm_NWAES) {
    class_<WasmAES>("AES")
          .class_function("encryptCBC", &WasmAES::encryptCBC, allow_raw_pointers())
          .class_function("decryptCBC", &WasmAES::decryptCBC, allow_raw_pointers())
          .class_function("encryptCTR", &WasmAES::encryptCTR, allow_raw_pointers())
          .class_function("decryptCTR", &WasmAES::decryptCTR, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
