//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCoinType.h"
#include "NWData.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

struct NWPublicKey;

/// Represents Any blockchain address.
NW_EXPORT_CLASS
struct NWAnyAddress;

/// Compares NWo addresses for equality.
NW_EXPORT_STATIC_METHOD
bool NWAnyAddressEqual(struct NWAnyAddress* _Nonnull lhs, struct NWAnyAddress* _Nonnull rhs);

/// Determines if the string is a valid Any address.
NW_EXPORT_STATIC_METHOD
bool NWAnyAddressIsValid(NWString* _Nonnull string, enum NWCoinType coin);

/// Creates an address from a string representation.
NW_EXPORT_STATIC_METHOD
struct NWAnyAddress* _Nullable NWAnyAddressCreateWithString(NWString* _Nonnull string, enum NWCoinType coin);

/// Creates an address from a public key.
NW_EXPORT_STATIC_METHOD
struct NWAnyAddress* _Nonnull NWAnyAddressCreateWithPublicKey(struct NWPublicKey* _Nonnull publicKey, enum NWCoinType coin);

NW_EXPORT_METHOD
void NWAnyAddressDelete(struct NWAnyAddress* _Nonnull address);

/// Returns the address string representation.
NW_EXPORT_PROPERTY
NWString* _Nonnull NWAnyAddressDescription(struct NWAnyAddress* _Nonnull address);

/// Returns coin type of address.
NW_EXPORT_PROPERTY
enum NWCoinType NWAnyAddressCoin(struct NWAnyAddress* _Nonnull address);

/// Returns underlaying data (public key or key hash)
NW_EXPORT_PROPERTY
NWData* _Nonnull NWAnyAddressData(struct NWAnyAddress* _Nonnull address);

NW_EXTERN_C_END

