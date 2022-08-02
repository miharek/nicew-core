// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWAnyAddress.h>
#include <NiceWCore/NWPublicKey.h>

#include "./PublicKey.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmAnyAddress {
  public:
    NWAnyAddress *instance;
  public:
    WasmAnyAddress(NWAnyAddress *instance) : instance(instance) {}
    ~WasmAnyAddress() {
        NWAnyAddressDelete(instance);
    }
  public:
    static auto equal(WasmAnyAddress* lhs, WasmAnyAddress* rhs);
    static auto isValid(const std::string& string, NWCoinType coin);
    static auto createWithString(const std::string& string, NWCoinType coin) -> WasmAnyAddress*;
    static auto createWithPublicKey(WasmPublicKey* publicKey, NWCoinType coin) -> WasmAnyAddress*;
    auto description();
    auto coin();
    auto data();
}; // class AnyAddress

} // namespace NW::Wasm
