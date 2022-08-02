//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

struct NWPublicKey;

/// Represents a legacy Bitcoin address.
NW_EXPORT_CLASS
struct NWBitcoinAddress;

/// Compares two addresses for equality.
NW_EXPORT_STATIC_METHOD
bool NWBitcoinAddressEqual(struct NWBitcoinAddress *_Nonnull lhs, struct NWBitcoinAddress *_Nonnull rhs);

/// Determines if the data is a valid Bitcoin address.
NW_EXPORT_STATIC_METHOD
bool NWBitcoinAddressIsValid(NWData *_Nonnull data);

/// Determines if the string is a valid Bitcoin address.
NW_EXPORT_STATIC_METHOD
bool NWBitcoinAddressIsValidString(NWString *_Nonnull string);

/// Initializes an address from a base58 sring representaion.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinAddress *_Nullable NWBitcoinAddressCreateWithString(NWString *_Nonnull string);

/// Initializes an address from raw data.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinAddress *_Nullable NWBitcoinAddressCreateWithData(NWData *_Nonnull data);

/// Initializes an address from a public key and a prefix byte.
NW_EXPORT_STATIC_METHOD
struct NWBitcoinAddress *_Nullable NWBitcoinAddressCreateWithPublicKey(struct NWPublicKey *_Nonnull publicKey, uint8_t prefix);

NW_EXPORT_METHOD
void NWBitcoinAddressDelete(struct NWBitcoinAddress *_Nonnull address);

/// Returns the address base58 string representation.
NW_EXPORT_PROPERTY
NWString *_Nonnull NWBitcoinAddressDescription(struct NWBitcoinAddress *_Nonnull address);

/// Returns the address prefix.
NW_EXPORT_PROPERTY
uint8_t NWBitcoinAddressPrefix(struct NWBitcoinAddress *_Nonnull address);

/// Returns the keyhash data.
NW_EXPORT_PROPERTY
NWData *_Nonnull NWBitcoinAddressKeyhash(struct NWBitcoinAddress *_Nonnull address);

NW_EXTERN_C_END
