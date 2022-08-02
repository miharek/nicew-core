//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

/// Public key types
NW_EXPORT_ENUM(uint32_t)
enum NWPublicKeyType {
    NWPublicKeyTypeSECP256k1 = 0,
    NWPublicKeyTypeSECP256k1Extended = 1,
    NWPublicKeyTypeNIST256p1 = 2,
    NWPublicKeyTypeNIST256p1Extended = 3,
    NWPublicKeyTypeED25519 = 4,
    NWPublicKeyTypeED25519Blake2b = 5,
    NWPublicKeyTypeCURVE25519 = 6,
    NWPublicKeyTypeED25519Cardano = 7,
};

NW_EXTERN_C_END
