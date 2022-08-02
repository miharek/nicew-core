// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "Account.h"

namespace NW::Wasm {
auto WasmAccount::create(const std::string& address, NWCoinType coin, NWDerivation derivation, const std::string& derivationPath, const std::string& publicKey, const std::string& extendedPublicKey) -> WasmAccount* {
    NWAccount *instance = NWAccountCreate(&address, coin, derivation, &derivationPath, &publicKey, &extendedPublicKey);
    return new WasmAccount(instance);
}


auto WasmAccount::address() {
    return NWStringToStd(NWAccountAddress(instance));
}

auto WasmAccount::derivation() {
    return NWAccountDerivation(instance);
}

auto WasmAccount::derivationPath() {
    return NWStringToStd(NWAccountDerivationPath(instance));
}

auto WasmAccount::publicKey() {
    return NWStringToStd(NWAccountPublicKey(instance));
}

auto WasmAccount::extendedPublicKey() {
    return NWStringToStd(NWAccountExtendedPublicKey(instance));
}

auto WasmAccount::coin() {
    return NWAccountCoin(instance);
}



EMSCRIPTEN_BINDINGS(Wasm_NWAccount) {
    class_<WasmAccount>("Account")
          .class_function("create", &WasmAccount::create, allow_raw_pointers())
          .function("address", &WasmAccount::address, allow_raw_pointers())
          .function("derivation", &WasmAccount::derivation, allow_raw_pointers())
          .function("derivationPath", &WasmAccount::derivationPath, allow_raw_pointers())
          .function("publicKey", &WasmAccount::publicKey, allow_raw_pointers())
          .function("extendedPublicKey", &WasmAccount::extendedPublicKey, allow_raw_pointers())
          .function("coin", &WasmAccount::coin, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
