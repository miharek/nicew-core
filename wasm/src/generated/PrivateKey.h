// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWPrivateKey.h>
#include <NiceWCore/NWPublicKey.h>

#include "./PublicKey.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmPrivateKey {
  public:
    NWPrivateKey *instance;
  public:
    WasmPrivateKey(NWPrivateKey *instance) : instance(instance) {}
    ~WasmPrivateKey() {
        NWPrivateKeyDelete(instance);
    }
  public:
    static auto isValid(const std::string& data, NWCurve curve);
    static auto create() -> WasmPrivateKey*;
    static auto createWithData(const std::string& data) -> WasmPrivateKey*;
    static auto createCopy(WasmPrivateKey* key) -> WasmPrivateKey*;
    auto data();
    auto getPublicKeySecp256k1(bool compressed);
    auto getPublicKeyNist256p1();
    auto getPublicKeyEd25519();
    auto getPublicKeyEd25519Blake2b();
    auto getPublicKeyEd25519Cardano();
    auto getPublicKeyCurve25519();
    auto getSharedKey(WasmPublicKey* publicKey, NWCurve curve);
    auto sign(const std::string& digest, NWCurve curve);
    auto signAsDER(const std::string& digest);
    auto signZilliqaSchnorr(const std::string& message);
}; // class PrivateKey

} // namespace NW::Wasm
