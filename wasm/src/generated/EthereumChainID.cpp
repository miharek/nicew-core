// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWEthereumChainID.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWEthereumChainID) {
    enum_<NWEthereumChainID>("EthereumChainID")
        .value("ethereum", NWEthereumChainID::NWEthereumChainIDEthereum)
    ;
}

} // namespace NW::Wasm
