// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWEthereumAbi.h>
#include <NiceWCore/NWEthereumAbiFunction.h>

#include "./EthereumAbiFunction.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmEthereumAbi {
  public:
    static auto encode(WasmEthereumAbiFunction* fn);
    static auto decodeOutput(WasmEthereumAbiFunction* fn, const std::string& encoded);
    static auto decodeCall(const std::string& data, const std::string& abi);
    static auto encodeTyped(const std::string& messageJson);
}; // class EthereumAbi

} // namespace NW::Wasm
