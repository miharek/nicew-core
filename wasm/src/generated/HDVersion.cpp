// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWHDVersion.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWHDVersion) {
    enum_<NWHDVersion>("HDVersion")
        .value("none", NWHDVersion::NWHDVersionNone)
        .value("xpub", NWHDVersion::NWHDVersionXPUB)
        .value("xprv", NWHDVersion::NWHDVersionXPRV)
        .value("ypub", NWHDVersion::NWHDVersionYPUB)
        .value("yprv", NWHDVersion::NWHDVersionYPRV)
        .value("zpub", NWHDVersion::NWHDVersionZPUB)
    ;
}

} // namespace NW::Wasm
