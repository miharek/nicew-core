// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWBitcoinSigHashType.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWBitcoinSigHashType) {
    enum_<NWBitcoinSigHashType>("BitcoinSigHashType")
        .value("all", NWBitcoinSigHashType::NWBitcoinSigHashTypeAll)
        .value("none", NWBitcoinSigHashType::NWBitcoinSigHashTypeNone)
        .value("single", NWBitcoinSigHashType::NWBitcoinSigHashTypeSingle)
        .value("fork", NWBitcoinSigHashType::NWBitcoinSigHashTypeFork)
        .value("forkBTG", NWBitcoinSigHashType::NWBitcoinSigHashTypeForkBTG)
    ;
}

} // namespace NW::Wasm
