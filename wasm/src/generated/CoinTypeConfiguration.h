// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWCoinTypeConfiguration.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmCoinTypeConfiguration {
  public:
    static auto getSymbol(NWCoinType type);
    static auto getDecimals(NWCoinType type);
    static auto getTransactionURL(NWCoinType type, const std::string& transactionID);
    static auto getAccountURL(NWCoinType type, const std::string& accountID);
    static auto getID(NWCoinType type);
    static auto getName(NWCoinType type);
}; // class CoinTypeConfiguration

} // namespace NW::Wasm
