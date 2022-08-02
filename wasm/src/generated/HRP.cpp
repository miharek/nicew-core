// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWHRP.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

namespace NW::Wasm {

auto describeHRP(NWHRP value) -> std::string {
    switch (value) {
        case NWHRPUnknown: return "";
        case NWHRPBitcoin: return "bc";
        default: return "";
    }
}

EMSCRIPTEN_BINDINGS(Wasm_NWHRP) {
    enum_<NWHRP>("HRP")
        .value("unknown", NWHRP::NWHRPUnknown)
        .value("bitcoin", NWHRP::NWHRPBitcoin)
    ;
    function("describeHRP", describeHRP);
}

} // namespace NW::Wasm
