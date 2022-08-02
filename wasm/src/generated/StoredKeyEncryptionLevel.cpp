// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWStoredKeyEncryptionLevel.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWStoredKeyEncryptionLevel) {
    enum_<NWStoredKeyEncryptionLevel>("StoredKeyEncryptionLevel")
        .value("default", NWStoredKeyEncryptionLevel::NWStoredKeyEncryptionLevelDefault)
        .value("minimal", NWStoredKeyEncryptionLevel::NWStoredKeyEncryptionLevelMinimal)
        .value("weak", NWStoredKeyEncryptionLevel::NWStoredKeyEncryptionLevelWeak)
        .value("standard", NWStoredKeyEncryptionLevel::NWStoredKeyEncryptionLevelStandard)
    ;
}

} // namespace NW::Wasm
