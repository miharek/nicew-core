// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <NiceWCore/NWBitcoinSigHashType.h>
#include <NiceWCore/NWCoinType.h>

namespace NW::Bitcoin {

// Defines the number of bits of the hash type which is used to identify which
// outputs are signed.
static const uint32_t SigHashMask = 0x1f;

// Return the default HashType for the given coin, such as NWBitcoinSigHashTypeAll.
inline enum NWBitcoinSigHashType hashTypeForCoin(enum NWCoinType coinType) {
    // set fork hash type for BCH and XEC
    switch (coinType) {
        case NWCoinTypeBitcoinCash:
        case NWCoinTypeECash:
            return (NWBitcoinSigHashType)((uint32_t)NWBitcoinSigHashTypeAll | (uint32_t)NWBitcoinSigHashTypeFork);
        case NWCoinTypeBitcoinGold:
            return (NWBitcoinSigHashType)((uint32_t)NWBitcoinSigHashTypeAll | (uint32_t)NWBitcoinSigHashTypeForkBTG);
        default:
            return NWBitcoinSigHashTypeAll;
    }
}

inline bool hashTypeIsSingle(enum NWBitcoinSigHashType type) { return ((uint32_t)type & SigHashMask) == (uint32_t)NWBitcoinSigHashTypeSingle; }

inline bool hashTypeIsNone(enum NWBitcoinSigHashType type) { return ((uint32_t)type & SigHashMask) == (uint32_t)NWBitcoinSigHashTypeNone; }

} // namespace NW::Bitcoin
