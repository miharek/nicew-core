// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#pragma once

#include <NiceWCore/NWTransactionCompiler.h>
#include <NiceWCore/NWDataVector.h>

#include "./DataVector.h"

#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

#include "../WasmString.h"
#include "../WasmData.h"

namespace NW::Wasm {

class WasmTransactionCompiler {
  public:
    static auto buildInput(NWCoinType coinType, const std::string& from, const std::string& to, const std::string& amount, const std::string& asset, const std::string& memo, const std::string& chainId);
    static auto preImageHashes(NWCoinType coinType, const std::string& txInputData);
    static auto compileWithSignatures(NWCoinType coinType, const std::string& txInputData, WasmDataVector* signatures, WasmDataVector* publicKeys);
}; // class TransactionCompiler

} // namespace NW::Wasm
