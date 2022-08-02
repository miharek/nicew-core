//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWString.h"
#include "NWCoinType.h"
#include "NWDerivation.h"

NW_EXTERN_C_BEGIN

/// Account for a particular coin within a wallet.
NW_EXPORT_CLASS
struct NWAccount;

NW_EXPORT_STATIC_METHOD
struct NWAccount *_Nonnull NWAccountCreate(NWString *_Nonnull address, enum NWCoinType coin, enum NWDerivation derivation, NWString *_Nonnull derivationPath, NWString *_Nonnull publicKey, NWString *_Nonnull extendedPublicKey);

NW_EXPORT_METHOD
void NWAccountDelete(struct NWAccount *_Nonnull account);

NW_EXPORT_PROPERTY
NWString *_Nonnull NWAccountAddress(struct NWAccount *_Nonnull account);

NW_EXPORT_PROPERTY
enum NWDerivation NWAccountDerivation(struct NWAccount *_Nonnull account);

NW_EXPORT_PROPERTY
NWString *_Nonnull NWAccountDerivationPath(struct NWAccount *_Nonnull account);

NW_EXPORT_PROPERTY
NWString *_Nonnull NWAccountPublicKey(struct NWAccount *_Nonnull account);

NW_EXPORT_PROPERTY
NWString *_Nonnull NWAccountExtendedPublicKey(struct NWAccount *_Nonnull account);

NW_EXPORT_PROPERTY
enum NWCoinType NWAccountCoin(struct NWAccount *_Nonnull account);

NW_EXTERN_C_END
