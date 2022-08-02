//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

/// Preset encryption parameter with different security strength, for key store
NW_EXPORT_ENUM(uint32_t)
enum NWStoredKeyEncryptionLevel {
    /// Default, which is one of the below values, determined by the implementation.
    NWStoredKeyEncryptionLevelDefault = 0,
    /// Minimal sufficient level of encryption strength (scrypt 4096)
    NWStoredKeyEncryptionLevelMinimal = 1,
    /// Weak encryption strength (scrypt 16k)
    NWStoredKeyEncryptionLevelWeak = 2,
    /// Standard level of encryption strength (scrypt 262k)
    NWStoredKeyEncryptionLevelStandard = 3,
};

NW_EXTERN_C_END

