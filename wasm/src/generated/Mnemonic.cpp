// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "Mnemonic.h"

namespace NW::Wasm {
auto WasmMnemonic::isValid(const std::string& mnemonic) {
    return NWMnemonicIsValid(&mnemonic);
}
auto WasmMnemonic::isValidWord(const std::string& word) {
    return NWMnemonicIsValidWord(&word);
}
auto WasmMnemonic::suggest(const std::string& prefix) {
    return NWStringToStd(NWMnemonicSuggest(&prefix));
}



EMSCRIPTEN_BINDINGS(Wasm_NWMnemonic) {
    class_<WasmMnemonic>("Mnemonic")
          .class_function("isValid", &WasmMnemonic::isValid, allow_raw_pointers())
          .class_function("isValidWord", &WasmMnemonic::isValidWord, allow_raw_pointers())
          .class_function("suggest", &WasmMnemonic::suggest, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
