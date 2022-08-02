// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWDerivation.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWDerivation) {
    enum_<NWDerivation>("Derivation")
        .value("default", NWDerivation::NWDerivationDefault)
        .value("custom", NWDerivation::NWDerivationCustom)
        .value("bitcoinSegwit", NWDerivation::NWDerivationBitcoinSegwit)
        .value("bitcoinLegacy", NWDerivation::NWDerivationBitcoinLegacy)
    ;
}

} // namespace NW::Wasm
