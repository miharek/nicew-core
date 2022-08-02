// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "StoredKey.h"

namespace NW::Wasm {
auto WasmStoredKey::load(const std::string& path) {
    return new WasmStoredKey(NWStoredKeyLoad(&path));
}
auto WasmStoredKey::importPrivateKey(const std::string& privateKey, const std::string& name, const std::string& password, NWCoinType coin) {
    auto privateKeyData = NW::data(privateKey);
    auto passwordData = NW::data(password);
    return new WasmStoredKey(NWStoredKeyImportPrivateKey(&privateKeyData, &name, &passwordData, coin));
}
auto WasmStoredKey::importHDWallet(const std::string& mnemonic, const std::string& name, const std::string& password, NWCoinType coin) {
    auto passwordData = NW::data(password);
    return new WasmStoredKey(NWStoredKeyImportHDWallet(&mnemonic, &name, &passwordData, coin));
}
auto WasmStoredKey::importJSON(const std::string& json) {
    auto jsonData = NW::data(json);
    return new WasmStoredKey(NWStoredKeyImportJSON(&jsonData));
}
auto WasmStoredKey::createLevel(const std::string& name, const std::string& password, NWStoredKeyEncryptionLevel encryptionLevel) -> WasmStoredKey* {
    auto passwordData = NW::data(password);
    NWStoredKey *instance = NWStoredKeyCreateLevel(&name, &passwordData, encryptionLevel);
    return new WasmStoredKey(instance);
}

auto WasmStoredKey::create(const std::string& name, const std::string& password) -> WasmStoredKey* {
    auto passwordData = NW::data(password);
    NWStoredKey *instance = NWStoredKeyCreate(&name, &passwordData);
    return new WasmStoredKey(instance);
}


auto WasmStoredKey::identifier() {
    return NWStringToStd(NWStoredKeyIdentifier(instance));
}

auto WasmStoredKey::name() {
    return NWStringToStd(NWStoredKeyName(instance));
}

auto WasmStoredKey::isMnemonic() {
    return NWStoredKeyIsMnemonic(instance);
}

auto WasmStoredKey::accountCount() {
    return NWStoredKeyAccountCount(instance);
}

auto WasmStoredKey::encryptionParameters() {
    return NWStringToStd(NWStoredKeyEncryptionParameters(instance));
}


auto WasmStoredKey::account(size_t index) {
    return new WasmAccount(NWStoredKeyAccount(instance, index));
}

auto WasmStoredKey::accountForCoin(NWCoinType coin, WasmHDWallet* wallet) {
    return new WasmAccount(NWStoredKeyAccountForCoin(instance, coin, wallet->instance));
}

auto WasmStoredKey::accountForCoinDerivation(NWCoinType coin, NWDerivation derivation, WasmHDWallet* wallet) {
    return new WasmAccount(NWStoredKeyAccountForCoinDerivation(instance, coin, derivation, wallet->instance));
}

auto WasmStoredKey::addAccountDerivation(const std::string& address, NWCoinType coin, NWDerivation derivation, const std::string& derivationPath, const std::string& publicKey, const std::string& extendedPublicKey) {
    return NWStoredKeyAddAccountDerivation(instance, &address, coin, derivation, &derivationPath, &publicKey, &extendedPublicKey);
}

auto WasmStoredKey::addAccount(const std::string& address, NWCoinType coin, const std::string& derivationPath, const std::string& publicKey, const std::string& extendedPublicKey) {
    return NWStoredKeyAddAccount(instance, &address, coin, &derivationPath, &publicKey, &extendedPublicKey);
}

auto WasmStoredKey::removeAccountForCoin(NWCoinType coin) {
    return NWStoredKeyRemoveAccountForCoin(instance, coin);
}

auto WasmStoredKey::removeAccountForCoinDerivation(NWCoinType coin, NWDerivation derivation) {
    return NWStoredKeyRemoveAccountForCoinDerivation(instance, coin, derivation);
}

auto WasmStoredKey::removeAccountForCoinDerivationPath(NWCoinType coin, const std::string& derivationPath) {
    return NWStoredKeyRemoveAccountForCoinDerivationPath(instance, coin, &derivationPath);
}

auto WasmStoredKey::store(const std::string& path) {
    return NWStoredKeyStore(instance, &path);
}

auto WasmStoredKey::decryptPrivateKey(const std::string& password) {
    auto passwordData = NW::data(password);
    return NWDataToVal(NWStoredKeyDecryptPrivateKey(instance, &passwordData));
}

auto WasmStoredKey::decryptMnemonic(const std::string& password) {
    auto passwordData = NW::data(password);
    return NWStringToStd(NWStoredKeyDecryptMnemonic(instance, &passwordData));
}

auto WasmStoredKey::privateKey(NWCoinType coin, const std::string& password) {
    auto passwordData = NW::data(password);
    return new WasmPrivateKey(NWStoredKeyPrivateKey(instance, coin, &passwordData));
}

auto WasmStoredKey::wallet(const std::string& password) {
    auto passwordData = NW::data(password);
    return new WasmHDWallet(NWStoredKeyWallet(instance, &passwordData));
}

auto WasmStoredKey::exportJSON() {
    return NWDataToVal(NWStoredKeyExportJSON(instance));
}

auto WasmStoredKey::fixAddresses(const std::string& password) {
    auto passwordData = NW::data(password);
    return NWStoredKeyFixAddresses(instance, &passwordData);
}


EMSCRIPTEN_BINDINGS(Wasm_NWStoredKey) {
    class_<WasmStoredKey>("StoredKey")
          .class_function("load", &WasmStoredKey::load, allow_raw_pointers())
          .class_function("importPrivateKey", &WasmStoredKey::importPrivateKey, allow_raw_pointers())
          .class_function("importHDWallet", &WasmStoredKey::importHDWallet, allow_raw_pointers())
          .class_function("importJSON", &WasmStoredKey::importJSON, allow_raw_pointers())
          .class_function("createLevel", &WasmStoredKey::createLevel, allow_raw_pointers())
          .class_function("create", &WasmStoredKey::create, allow_raw_pointers())
          .function("identifier", &WasmStoredKey::identifier, allow_raw_pointers())
          .function("name", &WasmStoredKey::name, allow_raw_pointers())
          .function("isMnemonic", &WasmStoredKey::isMnemonic, allow_raw_pointers())
          .function("accountCount", &WasmStoredKey::accountCount, allow_raw_pointers())
          .function("encryptionParameters", &WasmStoredKey::encryptionParameters, allow_raw_pointers())
          .function("account", &WasmStoredKey::account, allow_raw_pointers())
          .function("accountForCoin", &WasmStoredKey::accountForCoin, allow_raw_pointers())
          .function("accountForCoinDerivation", &WasmStoredKey::accountForCoinDerivation, allow_raw_pointers())
          .function("addAccountDerivation", &WasmStoredKey::addAccountDerivation, allow_raw_pointers())
          .function("addAccount", &WasmStoredKey::addAccount, allow_raw_pointers())
          .function("removeAccountForCoin", &WasmStoredKey::removeAccountForCoin, allow_raw_pointers())
          .function("removeAccountForCoinDerivation", &WasmStoredKey::removeAccountForCoinDerivation, allow_raw_pointers())
          .function("removeAccountForCoinDerivationPath", &WasmStoredKey::removeAccountForCoinDerivationPath, allow_raw_pointers())
          .function("store", &WasmStoredKey::store, allow_raw_pointers())
          .function("decryptPrivateKey", &WasmStoredKey::decryptPrivateKey, allow_raw_pointers())
          .function("decryptMnemonic", &WasmStoredKey::decryptMnemonic, allow_raw_pointers())
          .function("privateKey", &WasmStoredKey::privateKey, allow_raw_pointers())
          .function("wallet", &WasmStoredKey::wallet, allow_raw_pointers())
          .function("exportJSON", &WasmStoredKey::exportJSON, allow_raw_pointers())
          .function("fixAddresses", &WasmStoredKey::fixAddresses, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
