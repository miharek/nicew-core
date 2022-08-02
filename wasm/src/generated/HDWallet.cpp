// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "HDWallet.h"

namespace NW::Wasm {
auto WasmHDWallet::getPublicKeyFromExtended(const std::string& extended, NWCoinType coin, const std::string& derivationPath) {
    return new WasmPublicKey(NWHDWalletGetPublicKeyFromExtended(&extended, coin, &derivationPath));
}
auto WasmHDWallet::create(int strength, const std::string& passphrase) -> WasmHDWallet* {
    NWHDWallet *instance = NWHDWalletCreate(strength, &passphrase);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmHDWallet(instance);
}

auto WasmHDWallet::createWithMnemonic(const std::string& mnemonic, const std::string& passphrase) -> WasmHDWallet* {
    NWHDWallet *instance = NWHDWalletCreateWithMnemonic(&mnemonic, &passphrase);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmHDWallet(instance);
}

auto WasmHDWallet::createWithMnemonicCheck(const std::string& mnemonic, const std::string& passphrase, bool check) -> WasmHDWallet* {
    NWHDWallet *instance = NWHDWalletCreateWithMnemonicCheck(&mnemonic, &passphrase, check);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmHDWallet(instance);
}

auto WasmHDWallet::createWithEntropy(const std::string& entropy, const std::string& passphrase) -> WasmHDWallet* {
    auto entropyData = NW::data(entropy);
    NWHDWallet *instance = NWHDWalletCreateWithEntropy(&entropyData, &passphrase);
    if (instance == nullptr) {
        return nullptr;
    }
    return new WasmHDWallet(instance);
}


auto WasmHDWallet::seed() {
    return NWDataToVal(NWHDWalletSeed(instance));
}

auto WasmHDWallet::mnemonic() {
    return NWStringToStd(NWHDWalletMnemonic(instance));
}

auto WasmHDWallet::entropy() {
    return NWDataToVal(NWHDWalletEntropy(instance));
}


auto WasmHDWallet::getMasterKey(NWCurve curve) {
    return new WasmPrivateKey(NWHDWalletGetMasterKey(instance, curve));
}

auto WasmHDWallet::getKeyForCoin(NWCoinType coin) {
    return new WasmPrivateKey(NWHDWalletGetKeyForCoin(instance, coin));
}

auto WasmHDWallet::getAddressForCoin(NWCoinType coin) {
    return NWStringToStd(NWHDWalletGetAddressForCoin(instance, coin));
}

auto WasmHDWallet::getKey(NWCoinType coin, const std::string& derivationPath) {
    return new WasmPrivateKey(NWHDWalletGetKey(instance, coin, &derivationPath));
}

auto WasmHDWallet::getDerivedKey(NWCoinType coin, uint32_t account, uint32_t change, uint32_t address) {
    return new WasmPrivateKey(NWHDWalletGetDerivedKey(instance, coin, account, change, address));
}

auto WasmHDWallet::getExtendedPrivateKey(NWPurpose purpose, NWCoinType coin, NWHDVersion version) {
    return NWStringToStd(NWHDWalletGetExtendedPrivateKey(instance, purpose, coin, version));
}

auto WasmHDWallet::getExtendedPublicKey(NWPurpose purpose, NWCoinType coin, NWHDVersion version) {
    return NWStringToStd(NWHDWalletGetExtendedPublicKey(instance, purpose, coin, version));
}

auto WasmHDWallet::getExtendedPrivateKeyAccount(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account) {
    return NWStringToStd(NWHDWalletGetExtendedPrivateKeyAccount(instance, purpose, coin, derivation, version, account));
}

auto WasmHDWallet::getExtendedPublicKeyAccount(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version, uint32_t account) {
    return NWStringToStd(NWHDWalletGetExtendedPublicKeyAccount(instance, purpose, coin, derivation, version, account));
}

auto WasmHDWallet::getExtendedPrivateKeyDerivation(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version) {
    return NWStringToStd(NWHDWalletGetExtendedPrivateKeyDerivation(instance, purpose, coin, derivation, version));
}

auto WasmHDWallet::getExtendedPublicKeyDerivation(NWPurpose purpose, NWCoinType coin, NWDerivation derivation, NWHDVersion version) {
    return NWStringToStd(NWHDWalletGetExtendedPublicKeyDerivation(instance, purpose, coin, derivation, version));
}


EMSCRIPTEN_BINDINGS(Wasm_NWHDWallet) {
    class_<WasmHDWallet>("HDWallet")
          .class_function("create", &WasmHDWallet::create, allow_raw_pointers())
          .class_function("createWithMnemonic", &WasmHDWallet::createWithMnemonic, allow_raw_pointers())
          .class_function("createWithMnemonicCheck", &WasmHDWallet::createWithMnemonicCheck, allow_raw_pointers())
          .class_function("createWithEntropy", &WasmHDWallet::createWithEntropy, allow_raw_pointers())
          .class_function("getPublicKeyFromExtended", &WasmHDWallet::getPublicKeyFromExtended, allow_raw_pointers())
          .function("seed", &WasmHDWallet::seed, allow_raw_pointers())
          .function("mnemonic", &WasmHDWallet::mnemonic, allow_raw_pointers())
          .function("entropy", &WasmHDWallet::entropy, allow_raw_pointers())
          .function("getMasterKey", &WasmHDWallet::getMasterKey, allow_raw_pointers())
          .function("getKeyForCoin", &WasmHDWallet::getKeyForCoin, allow_raw_pointers())
          .function("getAddressForCoin", &WasmHDWallet::getAddressForCoin, allow_raw_pointers())
          .function("getKey", &WasmHDWallet::getKey, allow_raw_pointers())
          .function("getDerivedKey", &WasmHDWallet::getDerivedKey, allow_raw_pointers())
          .function("getExtendedPrivateKey", &WasmHDWallet::getExtendedPrivateKey, allow_raw_pointers())
          .function("getExtendedPublicKey", &WasmHDWallet::getExtendedPublicKey, allow_raw_pointers())
          .function("getExtendedPrivateKeyAccount", &WasmHDWallet::getExtendedPrivateKeyAccount, allow_raw_pointers())
          .function("getExtendedPublicKeyAccount", &WasmHDWallet::getExtendedPublicKeyAccount, allow_raw_pointers())
          .function("getExtendedPrivateKeyDerivation", &WasmHDWallet::getExtendedPrivateKeyDerivation, allow_raw_pointers())
          .function("getExtendedPublicKeyDerivation", &WasmHDWallet::getExtendedPublicKeyDerivation, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
