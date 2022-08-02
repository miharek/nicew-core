// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWDataVector.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmDataVector {
  public:
    NWDataVector *instance;
  public:
    WasmDataVector(NWDataVector *instance) : instance(instance) {}
    ~WasmDataVector() {
        NWDataVectorDelete(instance);
    }
  public:
    static auto create() -> WasmDataVector*;
    static auto createWithData(const std::string& data) -> WasmDataVector*;
    auto size();
    auto add(const std::string& data);
    auto get(size_t index);
}; // class DataVector

} // namespace NW::Wasm
