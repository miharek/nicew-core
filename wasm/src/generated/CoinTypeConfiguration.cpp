// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include "CoinTypeConfiguration.h"

namespace NW::Wasm {
auto WasmCoinTypeConfiguration::getSymbol(NWCoinType type) {
    return NWStringToStd(NWCoinTypeConfigurationGetSymbol(type));
}
auto WasmCoinTypeConfiguration::getDecimals(NWCoinType type) {
    return NWCoinTypeConfigurationGetDecimals(type);
}
auto WasmCoinTypeConfiguration::getTransactionURL(NWCoinType type, const std::string& transactionID) {
    return NWStringToStd(NWCoinTypeConfigurationGetTransactionURL(type, &transactionID));
}
auto WasmCoinTypeConfiguration::getAccountURL(NWCoinType type, const std::string& accountID) {
    return NWStringToStd(NWCoinTypeConfigurationGetAccountURL(type, &accountID));
}
auto WasmCoinTypeConfiguration::getID(NWCoinType type) {
    return NWStringToStd(NWCoinTypeConfigurationGetID(type));
}
auto WasmCoinTypeConfiguration::getName(NWCoinType type) {
    return NWStringToStd(NWCoinTypeConfigurationGetName(type));
}



EMSCRIPTEN_BINDINGS(Wasm_NWCoinTypeConfiguration) {
    class_<WasmCoinTypeConfiguration>("CoinTypeConfiguration")
          .class_function("getSymbol", &WasmCoinTypeConfiguration::getSymbol, allow_raw_pointers())
          .class_function("getDecimals", &WasmCoinTypeConfiguration::getDecimals, allow_raw_pointers())
          .class_function("getTransactionURL", &WasmCoinTypeConfiguration::getTransactionURL, allow_raw_pointers())
          .class_function("getAccountURL", &WasmCoinTypeConfiguration::getAccountURL, allow_raw_pointers())
          .class_function("getID", &WasmCoinTypeConfiguration::getID, allow_raw_pointers())
          .class_function("getName", &WasmCoinTypeConfiguration::getName, allow_raw_pointers())
    ;
}

} // namespace NW::Wasm
