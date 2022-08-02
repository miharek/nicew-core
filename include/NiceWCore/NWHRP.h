// Copyright © 2022 Mihael Rek
//
// This is a GENERATED FILE from \registry.json, changes made here WILL BE LOST.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

///  Registered human-readable parts for BIP-0173
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0173.md
NW_EXPORT_ENUM()
enum NWHRP {
    NWHRPUnknown     /* "" */,
    NWHRPBitcoin     /* "bc" */,
};

static const char *_Nonnull HRP_BITCOIN = "bc";

const char *_Nullable stringForHRP(enum NWHRP hrp);
enum NWHRP hrpForString(const char *_Nonnull string);

NW_EXTERN_C_END
