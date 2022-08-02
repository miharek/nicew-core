// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWHash.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmHash {
  public:
    static auto sha1(const std::string& data);
    static auto sha256(const std::string& data);
    static auto sha512(const std::string& data);
    static auto sha512_256(const std::string& data);
    static auto keccak256(const std::string& data);
    static auto keccak512(const std::string& data);
    static auto sha3_256(const std::string& data);
    static auto sha3_512(const std::string& data);
    static auto ripemd(const std::string& data);
    static auto blake256(const std::string& data);
    static auto blake2b(const std::string& data, size_t size);
    static auto groestl512(const std::string& data);
    static auto sha256SHA256(const std::string& data);
    static auto sha256RIPEMD(const std::string& data);
    static auto sha3_256RIPEMD(const std::string& data);
    static auto blake256Blake256(const std::string& data);
    static auto blake256RIPEMD(const std::string& data);
    static auto groestl512Groestl512(const std::string& data);
}; // class Hash

} // namespace NW::Wasm
