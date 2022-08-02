// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWEthereumAbiValue.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmEthereumAbiValue {
  public:
    static auto encodeBool(bool value);
    static auto encodeInt32(int32_t value);
    static auto encodeUInt32(uint32_t value);
    static auto encodeInt256(const std::string& value);
    static auto encodeUInt256(const std::string& value);
    static auto encodeAddress(const std::string& value);
    static auto encodeString(const std::string& value);
    static auto encodeBytes(const std::string& value);
    static auto encodeBytesDyn(const std::string& value);
    static auto decodeUInt256(const std::string& input);
    static auto decodeValue(const std::string& input, const std::string& type);
    static auto decodeArray(const std::string& input, const std::string& type);
}; // class EthereumAbiValue

} // namespace NW::Wasm
