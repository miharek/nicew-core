// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE, changes made here WILL BE LOST.
//

#include <NiceWCore/NWCurve.h>


#include <emscripten/bind.h>

using namespace emscripten;

#include <string>

namespace NW::Wasm {

auto describeCurve(NWCurve value) -> std::string {
    switch (value) {
        case NWCurveSECP256k1: return "secp256k1";
        case NWCurveED25519: return "ed25519";
        case NWCurveED25519Blake2bNano: return "ed25519-blake2b-nano";
        case NWCurveCurve25519: return "curve25519";
        case NWCurveNIST256p1: return "nist256p1";
        case NWCurveED25519ExtendedCardano: return "ed25519-cardano-seed";
        default: return "";
    }
}

EMSCRIPTEN_BINDINGS(Wasm_NWCurve) {
    enum_<NWCurve>("Curve")
        .value("secp256k1", NWCurve::NWCurveSECP256k1)
        .value("ed25519", NWCurve::NWCurveED25519)
        .value("ed25519Blake2bNano", NWCurve::NWCurveED25519Blake2bNano)
        .value("curve25519", NWCurve::NWCurveCurve25519)
        .value("nist256p1", NWCurve::NWCurveNIST256p1)
        .value("ed25519ExtendedCardano", NWCurve::NWCurveED25519ExtendedCardano)
    ;
    function("describeCurve", describeCurve);
}

} // namespace NW::Wasm
