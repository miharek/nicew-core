// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "TransactionCompiler.h"

namespace NW::Wasm {
auto WasmTransactionCompiler::buildInput(NWCoinType coinType, const std::string& from, const std::string& to, const std::string& amount, const std::string& asset, const std::string& memo, const std::string& chainId) {
    return NWDataToVal(NWTransactionCompilerBuildInput(coinType, &from, &to, &amount, &asset, &memo, &chainId));
}
auto WasmTransactionCompiler::preImageHashes(NWCoinType coinType, const std::string& txInputData) {
    auto txInputDataData = NW::data(txInputData);
    return NWDataToVal(NWTransactionCompilerPreImageHashes(coinType, &txInputDataData));
}
auto WasmTransactionCompiler::compileWithSignatures(NWCoinType coinType, const std::string& txInputData, WasmDataVector* signatures, WasmDataVector* publicKeys) {
    auto txInputDataData = NW::data(txInputData);
    return NWDataToVal(NWTransactionCompilerCompileWithSignatures(coinType, &txInputDataData, signatures->instance, publicKeys->instance));
}



EMSCRIPTEN_BINDINGS(Wasm_NWTransactionCompiler) {
    class_<WasmTransactionCompiler>("TransactionCompiler")
          .class_function("buildInput", &WasmTransactionCompiler::buildInput, allow_raw_pointers())
          .class_function("preImageHashes", &WasmTransactionCompiler::preImageHashes, allow_raw_pointers())
          .class_function("compileWithSignatures", &WasmTransactionCompiler::compileWithSignatures, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
