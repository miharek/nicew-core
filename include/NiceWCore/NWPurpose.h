//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

/// HD wallet purpose
///
/// See https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki
/// See https://github.com/bitcoin/bips/blob/master/bip-0049.mediawiki
/// See https://github.com/bitcoin/bips/blob/master/bip-0084.mediawiki
NW_EXPORT_ENUM(uint32_t)
enum NWPurpose {
    NWPurposeBIP44 = 44,
    NWPurposeBIP49 = 49, // Derivation scheme for P2WPKH-nested-in-P2SH
    NWPurposeBIP84 = 84, // Derivation scheme for P2WPKH
    NWPurposeBIP1852 = 1852, // Derivation scheme used by Cardano-Shelley
};

NW_EXTERN_C_END
