// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWBitcoinScript.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmBitcoinScript {
  public:
    NWBitcoinScript *instance;
  public:
    WasmBitcoinScript(NWBitcoinScript *instance) : instance(instance) {}
    ~WasmBitcoinScript() {
        NWBitcoinScriptDelete(instance);
    }
  public:
    static auto equal(WasmBitcoinScript* lhs, WasmBitcoinScript* rhs);
    static auto buildPayToPublicKey(const std::string& pubkey);
    static auto buildPayToPublicKeyHash(const std::string& hash);
    static auto buildPayToScriptHash(const std::string& scriptHash);
    static auto buildPayToWitnessPubkeyHash(const std::string& hash);
    static auto buildPayToWitnessScriptHash(const std::string& scriptHash);
    static auto lockScriptForAddress(const std::string& address, NWCoinType coin);
    static auto hashTypeForCoin(NWCoinType coinType);
    static auto create() -> WasmBitcoinScript*;
    static auto createWithData(const std::string& data) -> WasmBitcoinScript*;
    static auto createCopy(WasmBitcoinScript* script) -> WasmBitcoinScript*;
    auto size();
    auto data();
    auto scriptHash();
    auto isPayToScriptHash();
    auto isPayToWitnessScriptHash();
    auto isPayToWitnessPublicKeyHash();
    auto isWitnessProgram();
    auto matchPayToPubkey();
    auto matchPayToPubkeyHash();
    auto matchPayToScriptHash();
    auto matchPayToWitnessPublicKeyHash();
    auto matchPayToWitnessScriptHash();
    auto encode();
}; // class BitcoinScript

} // namespace NW::Wasm
