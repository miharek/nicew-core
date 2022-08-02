// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWPublicKey.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmPublicKey {
  public:
    NWPublicKey *instance;
  public:
    WasmPublicKey(NWPublicKey *instance) : instance(instance) {}
    ~WasmPublicKey() {
        NWPublicKeyDelete(instance);
    }
  public:
    static auto isValid(const std::string& data, NWPublicKeyType type);
    static auto recover(const std::string& signature, const std::string& message);
    static auto createWithData(const std::string& data, NWPublicKeyType type) -> WasmPublicKey*;
    auto isCompressed();
    auto compressed();
    auto uncompressed();
    auto data();
    auto keyType();
    auto description();
    auto verify(const std::string& signature, const std::string& message);
    auto verifyAsDER(const std::string& signature, const std::string& message);
    auto verifyZilliqaSchnorr(const std::string& signature, const std::string& message);
}; // class PublicKey

} // namespace NW::Wasm
