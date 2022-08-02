// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "EthereumAbi.h"

namespace NW::Wasm {
auto WasmEthereumAbi::encode(WasmEthereumAbiFunction* fn) {
    return NWDataToVal(NWEthereumAbiEncode(fn->instance));
}
auto WasmEthereumAbi::decodeOutput(WasmEthereumAbiFunction* fn, const std::string& encoded) {
    auto encodedData = NW::data(encoded);
    return NWEthereumAbiDecodeOutput(fn->instance, &encodedData);
}
auto WasmEthereumAbi::decodeCall(const std::string& data, const std::string& abi) {
    auto dataData = NW::data(data);
    return NWStringToStd(NWEthereumAbiDecodeCall(&dataData, &abi));
}
auto WasmEthereumAbi::encodeTyped(const std::string& messageJson) {
    return NWDataToVal(NWEthereumAbiEncodeTyped(&messageJson));
}



EMSCRIPTEN_BINDINGS(Wasm_NWEthereumAbi) {
    class_<WasmEthereumAbi>("EthereumAbi")
          .class_function("encode", &WasmEthereumAbi::encode, allow_raw_pointers())
          .class_function("decodeOutput", &WasmEthereumAbi::decodeOutput, allow_raw_pointers())
          .class_function("decodeCall", &WasmEthereumAbi::decodeCall, allow_raw_pointers())
          .class_function("encodeTyped", &WasmEthereumAbi::encodeTyped, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
