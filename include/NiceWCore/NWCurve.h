//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

/// Elliptic cruves
NW_EXPORT_ENUM()
enum NWCurve {
    NWCurveSECP256k1              /* "secp256k1" */,
    NWCurveED25519                /* "ed25519" */,
    NWCurveED25519Blake2bNano     /* "ed25519-blake2b-nano" */,
    NWCurveCurve25519             /* "curve25519" */,
    NWCurveNIST256p1              /* "nist256p1" */,
    NWCurveED25519ExtendedCardano /* "ed25519-cardano-seed" */,
    NWCurveNone
};

NW_EXTERN_C_END