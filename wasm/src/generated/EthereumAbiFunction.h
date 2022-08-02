// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWEthereumAbiFunction.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmEthereumAbiFunction {
  public:
    NWEthereumAbiFunction *instance;
  public:
    WasmEthereumAbiFunction(NWEthereumAbiFunction *instance) : instance(instance) {}
    ~WasmEthereumAbiFunction() {
        NWEthereumAbiFunctionDelete(instance);
    }
  public:
    static auto createWithString(const std::string& name) -> WasmEthereumAbiFunction*;
    auto getType();
    auto addParamUInt8(uint8_t val, bool isOutput);
    auto addParamUInt16(uint16_t val, bool isOutput);
    auto addParamUInt32(uint32_t val, bool isOutput);
    auto addParamUInt64(uint64_t val, bool isOutput);
    auto addParamUInt256(const std::string& val, bool isOutput);
    auto addParamUIntN(int bits, const std::string& val, bool isOutput);
    auto addParamInt8(int8_t val, bool isOutput);
    auto addParamInt16(int16_t val, bool isOutput);
    auto addParamInt32(int32_t val, bool isOutput);
    auto addParamInt64(int64_t val, bool isOutput);
    auto addParamInt256(const std::string& val, bool isOutput);
    auto addParamIntN(int bits, const std::string& val, bool isOutput);
    auto addParamBool(bool val, bool isOutput);
    auto addParamString(const std::string& val, bool isOutput);
    auto addParamAddress(const std::string& val, bool isOutput);
    auto addParamBytes(const std::string& val, bool isOutput);
    auto addParamBytesFix(size_t size, const std::string& val, bool isOutput);
    auto addParamArray(bool isOutput);
    auto getParamUInt8(int idx, bool isOutput);
    auto getParamUInt64(int idx, bool isOutput);
    auto getParamUInt256(int idx, bool isOutput);
    auto getParamBool(int idx, bool isOutput);
    auto getParamString(int idx, bool isOutput);
    auto getParamAddress(int idx, bool isOutput);
    auto addInArrayParamUInt8(int arrayIdx, uint8_t val);
    auto addInArrayParamUInt16(int arrayIdx, uint16_t val);
    auto addInArrayParamUInt32(int arrayIdx, uint32_t val);
    auto addInArrayParamUInt64(int arrayIdx, uint64_t val);
    auto addInArrayParamUInt256(int arrayIdx, const std::string& val);
    auto addInArrayParamUIntN(int arrayIdx, int bits, const std::string& val);
    auto addInArrayParamInt8(int arrayIdx, int8_t val);
    auto addInArrayParamInt16(int arrayIdx, int16_t val);
    auto addInArrayParamInt32(int arrayIdx, int32_t val);
    auto addInArrayParamInt64(int arrayIdx, int64_t val);
    auto addInArrayParamInt256(int arrayIdx, const std::string& val);
    auto addInArrayParamIntN(int arrayIdx, int bits, const std::string& val);
    auto addInArrayParamBool(int arrayIdx, bool val);
    auto addInArrayParamString(int arrayIdx, const std::string& val);
    auto addInArrayParamAddress(int arrayIdx, const std::string& val);
    auto addInArrayParamBytes(int arrayIdx, const std::string& val);
    auto addInArrayParamBytesFix(int arrayIdx, size_t size, const std::string& val);
}; // class EthereumAbiFunction

} // namespace NW::Wasm
