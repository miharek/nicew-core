// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWBase64.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmBase64 {
  public:
    static auto decode(const std::string& string);
    static auto decodeUrl(const std::string& string);
    static auto encode(const std::string& data);
    static auto encodeUrl(const std::string& data);
}; // class Base64

} // namespace NW::Wasm
