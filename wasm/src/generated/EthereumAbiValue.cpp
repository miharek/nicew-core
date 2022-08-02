// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "EthereumAbiValue.h"

namespace NW::Wasm {
auto WasmEthereumAbiValue::encodeBool(bool value) {
    return NWDataToVal(NWEthereumAbiValueEncodeBool(value));
}
auto WasmEthereumAbiValue::encodeInt32(int32_t value) {
    return NWDataToVal(NWEthereumAbiValueEncodeInt32(value));
}
auto WasmEthereumAbiValue::encodeUInt32(uint32_t value) {
    return NWDataToVal(NWEthereumAbiValueEncodeUInt32(value));
}
auto WasmEthereumAbiValue::encodeInt256(const std::string& value) {
    auto valueData = NW::data(value);
    return NWDataToVal(NWEthereumAbiValueEncodeInt256(&valueData));
}
auto WasmEthereumAbiValue::encodeUInt256(const std::string& value) {
    auto valueData = NW::data(value);
    return NWDataToVal(NWEthereumAbiValueEncodeUInt256(&valueData));
}
auto WasmEthereumAbiValue::encodeAddress(const std::string& value) {
    auto valueData = NW::data(value);
    return NWDataToVal(NWEthereumAbiValueEncodeAddress(&valueData));
}
auto WasmEthereumAbiValue::encodeString(const std::string& value) {
    return NWDataToVal(NWEthereumAbiValueEncodeString(&value));
}
auto WasmEthereumAbiValue::encodeBytes(const std::string& value) {
    auto valueData = NW::data(value);
    return NWDataToVal(NWEthereumAbiValueEncodeBytes(&valueData));
}
auto WasmEthereumAbiValue::encodeBytesDyn(const std::string& value) {
    auto valueData = NW::data(value);
    return NWDataToVal(NWEthereumAbiValueEncodeBytesDyn(&valueData));
}
auto WasmEthereumAbiValue::decodeUInt256(const std::string& input) {
    auto inputData = NW::data(input);
    return NWStringToStd(NWEthereumAbiValueDecodeUInt256(&inputData));
}
auto WasmEthereumAbiValue::decodeValue(const std::string& input, const std::string& type) {
    auto inputData = NW::data(input);
    return NWStringToStd(NWEthereumAbiValueDecodeValue(&inputData, &type));
}
auto WasmEthereumAbiValue::decodeArray(const std::string& input, const std::string& type) {
    auto inputData = NW::data(input);
    return NWStringToStd(NWEthereumAbiValueDecodeArray(&inputData, &type));
}



EMSCRIPTEN_BINDINGS(Wasm_NWEthereumAbiValue) {
    class_<WasmEthereumAbiValue>("EthereumAbiValue")
          .class_function("encodeBool", &WasmEthereumAbiValue::encodeBool, allow_raw_pointers())
          .class_function("encodeInt32", &WasmEthereumAbiValue::encodeInt32, allow_raw_pointers())
          .class_function("encodeUInt32", &WasmEthereumAbiValue::encodeUInt32, allow_raw_pointers())
          .class_function("encodeInt256", &WasmEthereumAbiValue::encodeInt256, allow_raw_pointers())
          .class_function("encodeUInt256", &WasmEthereumAbiValue::encodeUInt256, allow_raw_pointers())
          .class_function("encodeAddress", &WasmEthereumAbiValue::encodeAddress, allow_raw_pointers())
          .class_function("encodeString", &WasmEthereumAbiValue::encodeString, allow_raw_pointers())
          .class_function("encodeBytes", &WasmEthereumAbiValue::encodeBytes, allow_raw_pointers())
          .class_function("encodeBytesDyn", &WasmEthereumAbiValue::encodeBytesDyn, allow_raw_pointers())
          .class_function("decodeUInt256", &WasmEthereumAbiValue::decodeUInt256, allow_raw_pointers())
          .class_function("decodeValue", &WasmEthereumAbiValue::decodeValue, allow_raw_pointers())
          .class_function("decodeArray", &WasmEthereumAbiValue::decodeArray, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
