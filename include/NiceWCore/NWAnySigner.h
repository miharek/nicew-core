//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCoinType.h"
#include "NWData.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

/// Helper class to sign any transactions.
struct NWAnySigner;

/// Signs a transaction.
extern NWData *_Nonnull NWAnySignerSign(NWData *_Nonnull input, enum NWCoinType coin);

/// Signs a json transaction with private key.
extern NWString *_Nonnull NWAnySignerSignJSON(NWString *_Nonnull json, NWData *_Nonnull key, enum NWCoinType coin);

extern bool NWAnySignerSupportsJSON(enum NWCoinType coin);

/// Plan a transaction (for UTXO chains).
extern NWData *_Nonnull NWAnySignerPlan(NWData *_Nonnull input, enum NWCoinType coin);

NW_EXTERN_C_END
