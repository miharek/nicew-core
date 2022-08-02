// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWPublicKeyType.h>


#include <emscripten/bind.h>

using namespace emscripten;

namespace NW::Wasm {

EMSCRIPTEN_BINDINGS(Wasm_NWPublicKeyType) {
    enum_<NWPublicKeyType>("PublicKeyType")
        .value("secp256k1", NWPublicKeyType::NWPublicKeyTypeSECP256k1)
        .value("secp256k1Extended", NWPublicKeyType::NWPublicKeyTypeSECP256k1Extended)
        .value("nist256p1", NWPublicKeyType::NWPublicKeyTypeNIST256p1)
        .value("nist256p1Extended", NWPublicKeyType::NWPublicKeyTypeNIST256p1Extended)
        .value("ed25519", NWPublicKeyType::NWPublicKeyTypeED25519)
        .value("ed25519Blake2b", NWPublicKeyType::NWPublicKeyTypeED25519Blake2b)
        .value("curve25519", NWPublicKeyType::NWPublicKeyTypeCURVE25519)
        .value("ed25519Cardano", NWPublicKeyType::NWPublicKeyTypeED25519Cardano)
    ;
}

} // namespace NW::Wasm
