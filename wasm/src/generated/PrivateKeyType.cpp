// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWPrivateKeyType.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWPrivateKeyType) {
    enum_<NWPrivateKeyType>("PrivateKeyType")
        .value("default", NWPrivateKeyType::NWPrivateKeyTypeDefault)
        .value("cardano", NWPrivateKeyType::NWPrivateKeyTypeCardano)
    ;
}

} // namespace NW::Wasm
