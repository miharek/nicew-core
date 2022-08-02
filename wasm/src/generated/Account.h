// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWAccount.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmAccount {
  public:
    NWAccount *instance;
  public:
    WasmAccount(NWAccount *instance) : instance(instance) {}
    ~WasmAccount() {
        NWAccountDelete(instance);
    }
  public:
    static auto create(const std::string& address, NWCoinType coin, NWDerivation derivation, const std::string& derivationPath, const std::string& publicKey, const std::string& extendedPublicKey) -> WasmAccount*;
    auto address();
    auto derivation();
    auto derivationPath();
    auto publicKey();
    auto extendedPublicKey();
    auto coin();
}; // class Account

} // namespace NW::Wasm
