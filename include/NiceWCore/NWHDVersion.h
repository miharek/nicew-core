//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

///  Registered HD version bytes
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0132.md
NW_EXPORT_ENUM(uint32_t)
enum NWHDVersion {
    NWHDVersionNone = 0,

    // Bitcoin
    NWHDVersionXPUB = 0x0488b21e,
    NWHDVersionXPRV = 0x0488ade4,
    NWHDVersionYPUB = 0x049d7cb2,
    NWHDVersionYPRV = 0x049d7878,
    NWHDVersionZPUB = 0x04b24746,
    NWHDVersionZPRV = 0x04b2430c
};

NW_EXPORT_PROPERTY
bool NWHDVersionIsPublic(enum NWHDVersion version);

NW_EXPORT_PROPERTY
bool NWHDVersionIsPrivate(enum NWHDVersion version);

NW_EXTERN_C_END
