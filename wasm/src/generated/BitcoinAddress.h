// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWBitcoinAddress.h>
#include <NiceWCore/NWPublicKey.h>

#include "./PublicKey.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmBitcoinAddress {
  public:
    NWBitcoinAddress *instance;
  public:
    WasmBitcoinAddress(NWBitcoinAddress *instance) : instance(instance) {}
    ~WasmBitcoinAddress() {
        NWBitcoinAddressDelete(instance);
    }
  public:
    static auto equal(WasmBitcoinAddress* lhs, WasmBitcoinAddress* rhs);
    static auto isValid(const std::string& data);
    static auto isValidString(const std::string& string);
    static auto createWithString(const std::string& string) -> WasmBitcoinAddress*;
    static auto createWithData(const std::string& data) -> WasmBitcoinAddress*;
    static auto createWithPublicKey(WasmPublicKey* publicKey, uint8_t prefix) -> WasmBitcoinAddress*;
    auto description();
    auto prefix();
    auto keyhash();
}; // class BitcoinAddress

} // namespace NW::Wasm
