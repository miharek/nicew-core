// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWBlockchain.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWBlockchain) {
    enum_<NWBlockchain>("Blockchain")
        .value("bitcoin", NWBlockchain::NWBlockchainBitcoin)
    ;
}

} // namespace NW::Wasm
