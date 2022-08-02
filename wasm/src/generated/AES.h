// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWAES.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmAES {
  public:
    static auto encryptCBC(const std::string& key, const std::string& data, const std::string& iv, NWAESPaddingMode mode);
    static auto decryptCBC(const std::string& key, const std::string& data, const std::string& iv, NWAESPaddingMode mode);
    static auto encryptCTR(const std::string& key, const std::string& data, const std::string& iv);
    static auto decryptCTR(const std::string& key, const std::string& data, const std::string& iv);
}; // class AES

} // namespace NW::Wasm
