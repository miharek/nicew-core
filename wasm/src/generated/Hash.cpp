// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "Hash.h"

namespace NW::Wasm {
auto WasmHash::sha1(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA1(&dataData));
}
auto WasmHash::sha256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA256(&dataData));
}
auto WasmHash::sha512(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA512(&dataData));
}
auto WasmHash::sha512_256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA512_256(&dataData));
}
auto WasmHash::keccak256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashKeccak256(&dataData));
}
auto WasmHash::keccak512(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashKeccak512(&dataData));
}
auto WasmHash::sha3_256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA3_256(&dataData));
}
auto WasmHash::sha3_512(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA3_512(&dataData));
}
auto WasmHash::ripemd(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashRIPEMD(&dataData));
}
auto WasmHash::blake256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashBlake256(&dataData));
}
auto WasmHash::blake2b(const std::string& data, size_t size) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashBlake2b(&dataData, size));
}
auto WasmHash::groestl512(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashGroestl512(&dataData));
}
auto WasmHash::sha256SHA256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA256SHA256(&dataData));
}
auto WasmHash::sha256RIPEMD(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA256RIPEMD(&dataData));
}
auto WasmHash::sha3_256RIPEMD(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashSHA3_256RIPEMD(&dataData));
}
auto WasmHash::blake256Blake256(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashBlake256Blake256(&dataData));
}
auto WasmHash::blake256RIPEMD(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashBlake256RIPEMD(&dataData));
}
auto WasmHash::groestl512Groestl512(const std::string& data) {
    auto dataData = NW::data(data);
    return NWDataToVal(NWHashGroestl512Groestl512(&dataData));
}



EMSCRIPTEN_BINDINGS(Wasm_NWHash) {
    class_<WasmHash>("Hash")
          .class_function("sha1", &WasmHash::sha1, allow_raw_pointers())
          .class_function("sha256", &WasmHash::sha256, allow_raw_pointers())
          .class_function("sha512", &WasmHash::sha512, allow_raw_pointers())
          .class_function("sha512_256", &WasmHash::sha512_256, allow_raw_pointers())
          .class_function("keccak256", &WasmHash::keccak256, allow_raw_pointers())
          .class_function("keccak512", &WasmHash::keccak512, allow_raw_pointers())
          .class_function("sha3_256", &WasmHash::sha3_256, allow_raw_pointers())
          .class_function("sha3_512", &WasmHash::sha3_512, allow_raw_pointers())
          .class_function("ripemd", &WasmHash::ripemd, allow_raw_pointers())
          .class_function("blake256", &WasmHash::blake256, allow_raw_pointers())
          .class_function("blake2b", &WasmHash::blake2b, allow_raw_pointers())
          .class_function("groestl512", &WasmHash::groestl512, allow_raw_pointers())
          .class_function("sha256SHA256", &WasmHash::sha256SHA256, allow_raw_pointers())
          .class_function("sha256RIPEMD", &WasmHash::sha256RIPEMD, allow_raw_pointers())
          .class_function("sha3_256RIPEMD", &WasmHash::sha3_256RIPEMD, allow_raw_pointers())
          .class_function("blake256Blake256", &WasmHash::blake256Blake256, allow_raw_pointers())
          .class_function("blake256RIPEMD", &WasmHash::blake256RIPEMD, allow_raw_pointers())
          .class_function("groestl512Groestl512", &WasmHash::groestl512Groestl512, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
