// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWPBKDF2.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmPBKDF2 {
  public:
    static auto hmacSha256(const std::string& password, const std::string& salt, uint32_t iterations, uint32_t dkLen);
    static auto hmacSha512(const std::string& password, const std::string& salt, uint32_t iterations, uint32_t dkLen);
}; // class PBKDF2

} // namespace NW::Wasm
