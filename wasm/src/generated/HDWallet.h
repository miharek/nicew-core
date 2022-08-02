// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWHDWallet.h>
#include <NiceWCore/NWPublicKey.h>
#include <NiceWCore/NWPrivateKey.h>

#include "./PublicKey.h"
#include "./PrivateKey.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmHDWallet {
  public:
    NWHDWallet *instance;
  public:
    WasmHDWallet(NWHDWallet *instance) : instance(instance) {}
    ~WasmHDWallet() {
        NWHDWalletDelete(instance);
    }
  public:
    static auto getPublicKeyFromExtended(const std::string& extended, NWCoinType coin, const std::string& derivationPath);
    static auto create(int strength, const std::string& passphrase) -> WasmHDWallet*;
    static auto createWithMnemonic(const std::string& mnemonic, const std::string& passphrase) -> WasmHDWallet*;
    static auto createWithMnemonicCheck(const std::string& mnemonic, const std::string& passphrase, bool check) -> WasmHDWallet*;
    static auto createWithEntropy(const std::string& entropy, const std::string& passphrase) -> WasmHDWallet*;
    auto seed();
    auto mnemonic();
    auto entropy();
    auto getMasterKey(NWCurve curve);
    auto getKeyForCoin(NWCoinType coin);
    auto getAddressForCoin(NWCoinType coin);
    auto getKey(NWCoinType coin, const std::string& derivationPath);
    auto getDerivedKey(NWCoinType coin, uint32_t account, uint32_t change, uint32_t address);
    auto getExtendedPrivateKey(NWPurpose purpose, NWCoinType coin, NWHDVersion version);
    auto getExtendedPublicKey(NWPurpose purpose, NWCoinType coin, NWHDVersion version);
    auto getExtendedPrivateKeyAccount(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account);
    auto getExtendedPublicKeyAccount(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account);
    auto getExtendedPrivateKeyDerivation(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version);
    auto getExtendedPublicKeyDerivation(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version);
}; // class HDWallet

} // namespace NW::Wasm
