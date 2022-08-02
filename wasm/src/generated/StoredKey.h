// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWStoredKey.h>
#include <NiceWCore/NWAccount.h>
#include <NiceWCore/NWHDWallet.h>
#include <NiceWCore/NWPrivateKey.h>

#include "./Account.h"
#include "./HDWallet.h"
#include "./PrivateKey.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmStoredKey {
  public:
    NWStoredKey *instance;
  public:
    WasmStoredKey(NWStoredKey *instance) : instance(instance) {}
    ~WasmStoredKey() {
        NWStoredKeyDelete(instance);
    }
  public:
    static auto load(const std::string& path);
    static auto importPrivateKey(const std::string& privateKey, const std::string& name, const std::string& password, NWCoinType coin);
    static auto importHDWallet(const std::string& mnemonic, const std::string& name, const std::string& password, NWCoinType coin);
    static auto importJSON(const std::string& json);
    static auto createLevel(const std::string& name, const std::string& password, NWStoredKeyEncryptionLevel encryptionLevel) -> WasmStoredKey*;
    static auto create(const std::string& name, const std::string& password) -> WasmStoredKey*;
    auto identifier();
    auto name();
    auto isMnemonic();
    auto accountCount();
    auto encryptionParameters();
    auto account(size_t index);
    auto accountForCoin(NWCoinType coin, WasmHDWallet* wallet);
    auto accountForCoinDerivation(NWCoinType coin, NWDerivation derivation, WasmHDWallet* wallet);
    auto addAccountDerivation(const std::string& address, NWCoinType coin, NWDerivation derivation, const std::string& derivationPath, const std::string& publicKey, const std::string& extendedPublicKey);
    auto addAccount(const std::string& address, NWCoinType coin, const std::string& derivationPath, const std::string& publicKey, const std::string& extendedPublicKey);
    auto removeAccountForCoin(NWCoinType coin);
    auto removeAccountForCoinDerivation(NWCoinType coin, NWDerivation derivation);
    auto removeAccountForCoinDerivationPath(NWCoinType coin, const std::string& derivationPath);
    auto store(const std::string& path);
    auto decryptPrivateKey(const std::string& password);
    auto decryptMnemonic(const std::string& password);
    auto privateKey(NWCoinType coin, const std::string& password);
    auto wallet(const std::string& password);
    auto exportJSON();
    auto fixAddresses(const std::string& password);
}; // class StoredKey

} // namespace NW::Wasm
