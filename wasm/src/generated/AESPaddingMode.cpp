// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWAESPaddingMode.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWAESPaddingMode) {
    enum_<NWAESPaddingMode>("AESPaddingMode")
        .value("zero", NWAESPaddingMode::NWAESPaddingModeZero)
        .value("pkcs7", NWAESPaddingMode::NWAESPaddingModePKCS7)
    ;
}

} // namespace NW::Wasm
