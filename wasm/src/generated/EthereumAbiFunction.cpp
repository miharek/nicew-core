// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "EthereumAbiFunction.h"

namespace NW::Wasm {
auto WasmEthereumAbiFunction::createWithString(const std::string& name) -> WasmEthereumAbiFunction* {
    NWEthereumAbiFunction *instance = NWEthereumAbiFunctionCreateWithString(&name);
    return new WasmEthereumAbiFunction(instance);
}



auto WasmEthereumAbiFunction::getType() {
    return NWStringToStd(NWEthereumAbiFunctionGetType(instance));
}

auto WasmEthereumAbiFunction::addParamUInt8(uint8_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamUInt8(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamUInt16(uint16_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamUInt16(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamUInt32(uint32_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamUInt32(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamUInt64(uint64_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamUInt64(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamUInt256(const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamUInt256(instance, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamUIntN(int bits, const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamUIntN(instance, bits, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamInt8(int8_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamInt8(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamInt16(int16_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamInt16(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamInt32(int32_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamInt32(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamInt64(int64_t val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamInt64(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamInt256(const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamInt256(instance, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamIntN(int bits, const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamIntN(instance, bits, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamBool(bool val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamBool(instance, val, isOutput);
}

auto WasmEthereumAbiFunction::addParamString(const std::string& val, bool isOutput) {
    return NWEthereumAbiFunctionAddParamString(instance, &val, isOutput);
}

auto WasmEthereumAbiFunction::addParamAddress(const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamAddress(instance, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamBytes(const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamBytes(instance, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamBytesFix(size_t size, const std::string& val, bool isOutput) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddParamBytesFix(instance, size, &valData, isOutput);
}

auto WasmEthereumAbiFunction::addParamArray(bool isOutput) {
    return NWEthereumAbiFunctionAddParamArray(instance, isOutput);
}

auto WasmEthereumAbiFunction::getParamUInt8(int idx, bool isOutput) {
    return NWEthereumAbiFunctionGetParamUInt8(instance, idx, isOutput);
}

auto WasmEthereumAbiFunction::getParamUInt64(int idx, bool isOutput) {
    return NWEthereumAbiFunctionGetParamUInt64(instance, idx, isOutput);
}

auto WasmEthereumAbiFunction::getParamUInt256(int idx, bool isOutput) {
    return NWDataToVal(NWEthereumAbiFunctionGetParamUInt256(instance, idx, isOutput));
}

auto WasmEthereumAbiFunction::getParamBool(int idx, bool isOutput) {
    return NWEthereumAbiFunctionGetParamBool(instance, idx, isOutput);
}

auto WasmEthereumAbiFunction::getParamString(int idx, bool isOutput) {
    return NWStringToStd(NWEthereumAbiFunctionGetParamString(instance, idx, isOutput));
}

auto WasmEthereumAbiFunction::getParamAddress(int idx, bool isOutput) {
    return NWDataToVal(NWEthereumAbiFunctionGetParamAddress(instance, idx, isOutput));
}

auto WasmEthereumAbiFunction::addInArrayParamUInt8(int arrayIdx, uint8_t val) {
    return NWEthereumAbiFunctionAddInArrayParamUInt8(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamUInt16(int arrayIdx, uint16_t val) {
    return NWEthereumAbiFunctionAddInArrayParamUInt16(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamUInt32(int arrayIdx, uint32_t val) {
    return NWEthereumAbiFunctionAddInArrayParamUInt32(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamUInt64(int arrayIdx, uint64_t val) {
    return NWEthereumAbiFunctionAddInArrayParamUInt64(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamUInt256(int arrayIdx, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamUInt256(instance, arrayIdx, &valData);
}

auto WasmEthereumAbiFunction::addInArrayParamUIntN(int arrayIdx, int bits, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamUIntN(instance, arrayIdx, bits, &valData);
}

auto WasmEthereumAbiFunction::addInArrayParamInt8(int arrayIdx, int8_t val) {
    return NWEthereumAbiFunctionAddInArrayParamInt8(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamInt16(int arrayIdx, int16_t val) {
    return NWEthereumAbiFunctionAddInArrayParamInt16(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamInt32(int arrayIdx, int32_t val) {
    return NWEthereumAbiFunctionAddInArrayParamInt32(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamInt64(int arrayIdx, int64_t val) {
    return NWEthereumAbiFunctionAddInArrayParamInt64(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamInt256(int arrayIdx, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamInt256(instance, arrayIdx, &valData);
}

auto WasmEthereumAbiFunction::addInArrayParamIntN(int arrayIdx, int bits, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamIntN(instance, arrayIdx, bits, &valData);
}

auto WasmEthereumAbiFunction::addInArrayParamBool(int arrayIdx, bool val) {
    return NWEthereumAbiFunctionAddInArrayParamBool(instance, arrayIdx, val);
}

auto WasmEthereumAbiFunction::addInArrayParamString(int arrayIdx, const std::string& val) {
    return NWEthereumAbiFunctionAddInArrayParamString(instance, arrayIdx, &val);
}

auto WasmEthereumAbiFunction::addInArrayParamAddress(int arrayIdx, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamAddress(instance, arrayIdx, &valData);
}

auto WasmEthereumAbiFunction::addInArrayParamBytes(int arrayIdx, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamBytes(instance, arrayIdx, &valData);
}

auto WasmEthereumAbiFunction::addInArrayParamBytesFix(int arrayIdx, size_t size, const std::string& val) {
    auto valData = NW::data(val);
    return NWEthereumAbiFunctionAddInArrayParamBytesFix(instance, arrayIdx, size, &valData);
}


EMSCRIPTEN_BINDINGS(Wasm_NWEthereumAbiFunction) {
    class_<WasmEthereumAbiFunction>("EthereumAbiFunction")
          .class_function("createWithString", &WasmEthereumAbiFunction::createWithString, allow_raw_pointers())
          .function("getType", &WasmEthereumAbiFunction::getType, allow_raw_pointers())
          .function("addParamUInt8", &WasmEthereumAbiFunction::addParamUInt8, allow_raw_pointers())
          .function("addParamUInt16", &WasmEthereumAbiFunction::addParamUInt16, allow_raw_pointers())
          .function("addParamUInt32", &WasmEthereumAbiFunction::addParamUInt32, allow_raw_pointers())
          .function("addParamUInt64", &WasmEthereumAbiFunction::addParamUInt64, allow_raw_pointers())
          .function("addParamUInt256", &WasmEthereumAbiFunction::addParamUInt256, allow_raw_pointers())
          .function("addParamUIntN", &WasmEthereumAbiFunction::addParamUIntN, allow_raw_pointers())
          .function("addParamInt8", &WasmEthereumAbiFunction::addParamInt8, allow_raw_pointers())
          .function("addParamInt16", &WasmEthereumAbiFunction::addParamInt16, allow_raw_pointers())
          .function("addParamInt32", &WasmEthereumAbiFunction::addParamInt32, allow_raw_pointers())
          .function("addParamInt64", &WasmEthereumAbiFunction::addParamInt64, allow_raw_pointers())
          .function("addParamInt256", &WasmEthereumAbiFunction::addParamInt256, allow_raw_pointers())
          .function("addParamIntN", &WasmEthereumAbiFunction::addParamIntN, allow_raw_pointers())
          .function("addParamBool", &WasmEthereumAbiFunction::addParamBool, allow_raw_pointers())
          .function("addParamString", &WasmEthereumAbiFunction::addParamString, allow_raw_pointers())
          .function("addParamAddress", &WasmEthereumAbiFunction::addParamAddress, allow_raw_pointers())
          .function("addParamBytes", &WasmEthereumAbiFunction::addParamBytes, allow_raw_pointers())
          .function("addParamBytesFix", &WasmEthereumAbiFunction::addParamBytesFix, allow_raw_pointers())
          .function("addParamArray", &WasmEthereumAbiFunction::addParamArray, allow_raw_pointers())
          .function("getParamUInt8", &WasmEthereumAbiFunction::getParamUInt8, allow_raw_pointers())
          .function("getParamUInt64", &WasmEthereumAbiFunction::getParamUInt64, allow_raw_pointers())
          .function("getParamUInt256", &WasmEthereumAbiFunction::getParamUInt256, allow_raw_pointers())
          .function("getParamBool", &WasmEthereumAbiFunction::getParamBool, allow_raw_pointers())
          .function("getParamString", &WasmEthereumAbiFunction::getParamString, allow_raw_pointers())
          .function("getParamAddress", &WasmEthereumAbiFunction::getParamAddress, allow_raw_pointers())
          .function("addInArrayParamUInt8", &WasmEthereumAbiFunction::addInArrayParamUInt8, allow_raw_pointers())
          .function("addInArrayParamUInt16", &WasmEthereumAbiFunction::addInArrayParamUInt16, allow_raw_pointers())
          .function("addInArrayParamUInt32", &WasmEthereumAbiFunction::addInArrayParamUInt32, allow_raw_pointers())
          .function("addInArrayParamUInt64", &WasmEthereumAbiFunction::addInArrayParamUInt64, allow_raw_pointers())
          .function("addInArrayParamUInt256", &WasmEthereumAbiFunction::addInArrayParamUInt256, allow_raw_pointers())
          .function("addInArrayParamUIntN", &WasmEthereumAbiFunction::addInArrayParamUIntN, allow_raw_pointers())
          .function("addInArrayParamInt8", &WasmEthereumAbiFunction::addInArrayParamInt8, allow_raw_pointers())
          .function("addInArrayParamInt16", &WasmEthereumAbiFunction::addInArrayParamInt16, allow_raw_pointers())
          .function("addInArrayParamInt32", &WasmEthereumAbiFunction::addInArrayParamInt32, allow_raw_pointers())
          .function("addInArrayParamInt64", &WasmEthereumAbiFunction::addInArrayParamInt64, allow_raw_pointers())
          .function("addInArrayParamInt256", &WasmEthereumAbiFunction::addInArrayParamInt256, allow_raw_pointers())
          .function("addInArrayParamIntN", &WasmEthereumAbiFunction::addInArrayParamIntN, allow_raw_pointers())
          .function("addInArrayParamBool", &WasmEthereumAbiFunction::addInArrayParamBool, allow_raw_pointers())
          .function("addInArrayParamString", &WasmEthereumAbiFunction::addInArrayParamString, allow_raw_pointers())
          .function("addInArrayParamAddress", &WasmEthereumAbiFunction::addInArrayParamAddress, allow_raw_pointers())
          .function("addInArrayParamBytes", &WasmEthereumAbiFunction::addInArrayParamBytes, allow_raw_pointers())
          .function("addInArrayParamBytesFix", &WasmEthereumAbiFunction::addInArrayParamBytesFix, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
