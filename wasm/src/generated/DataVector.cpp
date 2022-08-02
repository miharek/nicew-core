// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "DataVector.h"

namespace NW::Wasm {
auto WasmDataVector::create() -> WasmDataVector* {
    NWDataVector *instance = NWDataVectorCreate();
    return new WasmDataVector(instance);
}

auto WasmDataVector::createWithData(const std::string& data) -> WasmDataVector* {
    auto dataData = NW::data(data);
    NWDataVector *instance = NWDataVectorCreateWithData(&dataData);
    return new WasmDataVector(instance);
}


auto WasmDataVector::size() {
    return NWDataVectorSize(instance);
}


auto WasmDataVector::add(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataVectorAdd(instance, &dataData);
}

auto WasmDataVector::get(size_t index) {
    return NWDataToVal(NWDataVectorGet(instance, index));
}


EMSCRIPTEN_BINDINGS(Wasm_NWDataVector) {
    class_<WasmDataVector>("DataVector")
          .class_function("create", &WasmDataVector::create, allow_raw_pointers())
          .class_function("createWithData", &WasmDataVector::createWithData, allow_raw_pointers())
          .function("size", &WasmDataVector::size, allow_raw_pointers())
          .function("add", &WasmDataVector::add, allow_raw_pointers())
          .function("get", &WasmDataVector::get, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
