// Copyright © 2017-2021 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.
//
// This is a GENERATED FILE from \registry.json, changes made here WILL BE LOST.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

/// Non-default coin address derivation names (default, unnamed derivations are not included).
NW_EXPORT_ENUM()
enum NWDerivation {
    NWDerivationDefault = 0, // default, for any coin
    NWDerivationCustom = 1, // custom, for any coin
    NWDerivationBitcoinSegwit = 2,
    NWDerivationBitcoinLegacy = 3,
};

NW_EXTERN_C_END
