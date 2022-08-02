// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWBlockchain.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

namespace NW::Wasm {

auto describeBlockchain(NWBlockchain value) -> std::string {
    switch (value) {
        default: return "";
    }
}

EMSCRIPTEN_BINDINGS(Wasm_NWBlockchain) {
    enum_<NWBlockchain>("Blockchain")
    ;
    function("describeBlockchain", describeBlockchain);
}

} // namespace NW::Wasm
