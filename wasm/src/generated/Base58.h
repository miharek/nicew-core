// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWBase58.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmBase58 {
  public:
    static auto encode(const std::string& data);
    static auto encodeNoCheck(const std::string& data);
    static auto decode(const std::string& string);
    static auto decodeNoCheck(const std::string& string);
}; // class Base58

} // namespace NW::Wasm
