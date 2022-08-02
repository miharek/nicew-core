// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWPurpose.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWPurpose) {
    enum_<NWPurpose>("Purpose")
        .value("bip44", NWPurpose::NWPurposeBIP44)
        .value("bip49", NWPurpose::NWPurposeBIP49)
        .value("bip84", NWPurpose::NWPurposeBIP84)
        .value("bip1852", NWPurpose::NWPurposeBIP1852)
    ;
}

} // namespace NW::Wasm
