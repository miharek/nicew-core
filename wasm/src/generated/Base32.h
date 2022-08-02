// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWBase32.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmBase32 {
  public:
    static auto decodeWithAlphabet(const std::string& string, const std::string& alphabet);
    static auto decode(const std::string& string);
    static auto encodeWithAlphabet(const std::string& data, const std::string& alphabet);
    static auto encode(const std::string& data);
}; // class Base32

} // namespace NW::Wasm
