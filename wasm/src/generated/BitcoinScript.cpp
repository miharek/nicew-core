// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "BitcoinScript.h"

namespace NW::Wasm {
auto WasmBitcoinScript::equal(WasmBitcoinScript* lhs, WasmBitcoinScript* rhs) {
    return NWBitcoinScriptEqual(lhs->instance, rhs->instance);
}
auto WasmBitcoinScript::buildPayToPublicKey(const std::string& pubkey) {
    auto pubkeyData = NW::data(pubkey);
    return new WasmBitcoinScript(NWBitcoinScriptBuildPayToPublicKey(&pubkeyData));
}
auto WasmBitcoinScript::buildPayToPublicKeyHash(const std::string& hash) {
    auto hashData = NW::data(hash);
    return new WasmBitcoinScript(NWBitcoinScriptBuildPayToPublicKeyHash(&hashData));
}
auto WasmBitcoinScript::buildPayToScriptHash(const std::string& scriptHash) {
    auto scriptHashData = NW::data(scriptHash);
    return new WasmBitcoinScript(NWBitcoinScriptBuildPayToScriptHash(&scriptHashData));
}
auto WasmBitcoinScript::buildPayToWitnessPubkeyHash(const std::string& hash) {
    auto hashData = NW::data(hash);
    return new WasmBitcoinScript(NWBitcoinScriptBuildPayToWitnessPubkeyHash(&hashData));
}
auto WasmBitcoinScript::buildPayToWitnessScriptHash(const std::string& scriptHash) {
    auto scriptHashData = NW::data(scriptHash);
    return new WasmBitcoinScript(NWBitcoinScriptBuildPayToWitnessScriptHash(&scriptHashData));
}
auto WasmBitcoinScript::lockScriptForAddress(const std::string& address, NWCoinType coin) {
    return new WasmBitcoinScript(NWBitcoinScriptLockScriptForAddress(&address, coin));
}
auto WasmBitcoinScript::hashTypeForCoin(NWCoinType coinType) {
    return NWBitcoinScriptHashTypeForCoin(coinType);
}
auto WasmBitcoinScript::create() -> WasmBitcoinScript* {
    NWBitcoinScript *instance = NWBitcoinScriptCreate();
    return new WasmBitcoinScript(instance);
}

auto WasmBitcoinScript::createWithData(const std::string& data) -> WasmBitcoinScript* {
    auto dataData = NW::data(data);
    NWBitcoinScript *instance = NWBitcoinScriptCreateWithData(&dataData);
    return new WasmBitcoinScript(instance);
}

auto WasmBitcoinScript::createCopy(WasmBitcoinScript* script) -> WasmBitcoinScript* {
    NWBitcoinScript *instance = NWBitcoinScriptCreateCopy(script->instance);
    return new WasmBitcoinScript(instance);
}


auto WasmBitcoinScript::size() {
    return NWBitcoinScriptSize(instance);
}

auto WasmBitcoinScript::data() {
    return NWDataToVal(NWBitcoinScriptData(instance));
}

auto WasmBitcoinScript::scriptHash() {
    return NWDataToVal(NWBitcoinScriptScriptHash(instance));
}

auto WasmBitcoinScript::isPayToScriptHash() {
    return NWBitcoinScriptIsPayToScriptHash(instance);
}

auto WasmBitcoinScript::isPayToWitnessScriptHash() {
    return NWBitcoinScriptIsPayToWitnessScriptHash(instance);
}

auto WasmBitcoinScript::isPayToWitnessPublicKeyHash() {
    return NWBitcoinScriptIsPayToWitnessPublicKeyHash(instance);
}

auto WasmBitcoinScript::isWitnessProgram() {
    return NWBitcoinScriptIsWitnessProgram(instance);
}


auto WasmBitcoinScript::matchPayToPubkey() {
    return NWDataToVal(NWBitcoinScriptMatchPayToPubkey(instance));
}

auto WasmBitcoinScript::matchPayToPubkeyHash() {
    return NWDataToVal(NWBitcoinScriptMatchPayToPubkeyHash(instance));
}

auto WasmBitcoinScript::matchPayToScriptHash() {
    return NWDataToVal(NWBitcoinScriptMatchPayToScriptHash(instance));
}

auto WasmBitcoinScript::matchPayToWitnessPublicKeyHash() {
    return NWDataToVal(NWBitcoinScriptMatchPayToWitnessPublicKeyHash(instance));
}

auto WasmBitcoinScript::matchPayToWitnessScriptHash() {
    return NWDataToVal(NWBitcoinScriptMatchPayToWitnessScriptHash(instance));
}

auto WasmBitcoinScript::encode() {
    return NWDataToVal(NWBitcoinScriptEncode(instance));
}


EMSCRIPTEN_BINDINGS(Wasm_NWBitcoinScript) {
    class_<WasmBitcoinScript>("BitcoinScript")
          .class_function("create", &WasmBitcoinScript::create, allow_raw_pointers())
          .class_function("createWithData", &WasmBitcoinScript::createWithData, allow_raw_pointers())
          .class_function("createCopy", &WasmBitcoinScript::createCopy, allow_raw_pointers())
          .class_function("equal", &WasmBitcoinScript::equal, allow_raw_pointers())
          .class_function("buildPayToPublicKey", &WasmBitcoinScript::buildPayToPublicKey, allow_raw_pointers())
          .class_function("buildPayToPublicKeyHash", &WasmBitcoinScript::buildPayToPublicKeyHash, allow_raw_pointers())
          .class_function("buildPayToScriptHash", &WasmBitcoinScript::buildPayToScriptHash, allow_raw_pointers())
          .class_function("buildPayToWitnessPubkeyHash", &WasmBitcoinScript::buildPayToWitnessPubkeyHash, allow_raw_pointers())
          .class_function("buildPayToWitnessScriptHash", &WasmBitcoinScript::buildPayToWitnessScriptHash, allow_raw_pointers())
          .class_function("lockScriptForAddress", &WasmBitcoinScript::lockScriptForAddress, allow_raw_pointers())
          .class_function("hashTypeForCoin", &WasmBitcoinScript::hashTypeForCoin, allow_raw_pointers())
          .function("size", &WasmBitcoinScript::size, allow_raw_pointers())
          .function("data", &WasmBitcoinScript::data, allow_raw_pointers())
          .function("scriptHash", &WasmBitcoinScript::scriptHash, allow_raw_pointers())
          .function("isPayToScriptHash", &WasmBitcoinScript::isPayToScriptHash, allow_raw_pointers())
          .function("isPayToWitnessScriptHash", &WasmBitcoinScript::isPayToWitnessScriptHash, allow_raw_pointers())
          .function("isPayToWitnessPublicKeyHash", &WasmBitcoinScript::isPayToWitnessPublicKeyHash, allow_raw_pointers())
          .function("isWitnessProgram", &WasmBitcoinScript::isWitnessProgram, allow_raw_pointers())
          .function("matchPayToPubkey", &WasmBitcoinScript::matchPayToPubkey, allow_raw_pointers())
          .function("matchPayToPubkeyHash", &WasmBitcoinScript::matchPayToPubkeyHash, allow_raw_pointers())
          .function("matchPayToScriptHash", &WasmBitcoinScript::matchPayToScriptHash, allow_raw_pointers())
          .function("matchPayToWitnessPublicKeyHash", &WasmBitcoinScript::matchPayToWitnessPublicKeyHash, allow_raw_pointers())
          .function("matchPayToWitnessScriptHash", &WasmBitcoinScript::matchPayToWitnessScriptHash, allow_raw_pointers())
          .function("encode", &WasmBitcoinScript::encode, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
