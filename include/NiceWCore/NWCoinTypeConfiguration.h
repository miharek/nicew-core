//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCoinType.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWCoinTypeConfiguration {
    uint8_t unused; // C doesn't allow zero-sized struct
};

/// Returns stock symbol of coin
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWCoinTypeConfigurationGetSymbol(enum NWCoinType type);

/// Returns max count decimal places for minimal coin unit
NW_EXPORT_STATIC_METHOD
int NWCoinTypeConfigurationGetDecimals(enum NWCoinType type);

/// Returns transaction url in blockchain explorer
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWCoinTypeConfigurationGetTransactionURL(enum NWCoinType type, NWString *_Nonnull transactionID);

/// Returns account url in blockchain explorer
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWCoinTypeConfigurationGetAccountURL(enum NWCoinType type, NWString *_Nonnull accountID);

/// Returns full name of coin in lower case
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWCoinTypeConfigurationGetID(enum NWCoinType type);

/// Returns full name of coin
NW_EXPORT_STATIC_METHOD
NWString *_Nonnull NWCoinTypeConfigurationGetName(enum NWCoinType type);

NW_EXTERN_C_END
