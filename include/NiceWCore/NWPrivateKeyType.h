//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

/// Private key types, the vast majority of chains use the default, 32-byte key.
NW_EXPORT_ENUM(uint32_t)
enum NWPrivateKeyType {
    NWPrivateKeyTypeDefault = 0,  // 32 bytes long
    NWPrivateKeyTypeCardano = 1,  // 2 extended keys plus chainCode, 96 bytes long, used by Cardano
};

NW_EXTERN_C_END
