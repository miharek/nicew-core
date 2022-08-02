// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWMnemonic.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmMnemonic {
  public:
    static auto isValid(const std::string& mnemonic);
    static auto isValidWord(const std::string& word);
    static auto suggest(const std::string& prefix);
}; // class Mnemonic

} // namespace NW::Wasm
