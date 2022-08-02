//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCoinType.h"
#include "NWData.h"
#include "NWHDWallet.h"
#include "NWPrivateKey.h"
#include "NWString.h"
#include "NWStoredKeyEncryptionLevel.h"
#include "NWDerivation.h"

NW_EXTERN_C_BEGIN

/// Represents a key stored as an encrypted file.
NW_EXPORT_CLASS
struct NWStoredKey;

/// Loads a key from a file.  Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWStoredKey* _Nullable NWStoredKeyLoad(NWString* _Nonnull path);

/// Imports a private key.  Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWStoredKey* _Nullable NWStoredKeyImportPrivateKey(NWData* _Nonnull privateKey, NWString* _Nonnull name, NWData* _Nonnull password, enum NWCoinType coin);

/// Imports an HD wallet.  Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWStoredKey* _Nullable NWStoredKeyImportHDWallet(NWString* _Nonnull mnemonic, NWString* _Nonnull name, NWData* _Nonnull password, enum NWCoinType coin);

/// Imports a key from JSON.  Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWStoredKey* _Nullable NWStoredKeyImportJSON(NWData* _Nonnull json);

/// Creates a new key, with given encryption strength level.  Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWStoredKey* _Nonnull NWStoredKeyCreateLevel(NWString* _Nonnull name, NWData* _Nonnull password, enum NWStoredKeyEncryptionLevel encryptionLevel);

/// DEPRECATED, use NWStoredKeyCreateLevel. Creates a new key.  Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWStoredKey* _Nonnull NWStoredKeyCreate(NWString* _Nonnull name, NWData* _Nonnull password);

NW_EXPORT_METHOD
void NWStoredKeyDelete(struct NWStoredKey* _Nonnull key);

/// Stored key unique identifier.  Returned object needs to be deleted.
NW_EXPORT_PROPERTY
NWString* _Nullable NWStoredKeyIdentifier(struct NWStoredKey* _Nonnull key);

/// Stored key namer.  Returned object needs to be deleted.
NW_EXPORT_PROPERTY
NWString* _Nonnull NWStoredKeyName(struct NWStoredKey* _Nonnull key);

/// Whether this key is a mnemonic phrase for a HD wallet.
NW_EXPORT_PROPERTY
bool NWStoredKeyIsMnemonic(struct NWStoredKey* _Nonnull key);

/// The number of accounts.
NW_EXPORT_PROPERTY
size_t NWStoredKeyAccountCount(struct NWStoredKey* _Nonnull key);

/// Returns the account at a given index.  Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWAccount* _Nullable NWStoredKeyAccount(struct NWStoredKey* _Nonnull key, size_t index);

/// Returns the account for a specific coin, creating it if necessary.  Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWAccount* _Nullable NWStoredKeyAccountForCoin(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, struct NWHDWallet* _Nullable wallet);

/// Returns the account for a specific coin + derivation, creating it if necessary.  Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWAccount* _Nullable NWStoredKeyAccountForCoinDerivation(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, enum NWDerivation derivation, struct NWHDWallet* _Nullable wallet);

/// Adds a new account, using given derivation (usually NWDerivationDefault) and derivation path (usually matches path from derivation, but custom possible).
NW_EXPORT_METHOD
void NWStoredKeyAddAccountDerivation(struct NWStoredKey* _Nonnull key, NWString* _Nonnull address, enum NWCoinType coin, enum NWDerivation derivation, NWString* _Nonnull derivationPath, NWString* _Nonnull publicKey, NWString* _Nonnull extendedPublicKey);

/// [Deprecated] Use NWStoredKeyAddAccountDerivation (with NWDerivationDefault) instead.
/// Adds a new account, using given derivation path.
NW_EXPORT_METHOD
void NWStoredKeyAddAccount(struct NWStoredKey* _Nonnull key, NWString* _Nonnull address, enum NWCoinType coin, NWString* _Nonnull derivationPath, NWString* _Nonnull publicKey, NWString* _Nonnull extendedPublicKey);

/// Remove the account for a specific coin
NW_EXPORT_METHOD
void NWStoredKeyRemoveAccountForCoin(struct NWStoredKey* _Nonnull key, enum NWCoinType coin);

/// Remove the account for a specific coin with the given derivation.
NW_EXPORT_METHOD
void NWStoredKeyRemoveAccountForCoinDerivation(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, enum NWDerivation derivation);

/// Remove the account for a specific coin with the given derivation path.
NW_EXPORT_METHOD
void NWStoredKeyRemoveAccountForCoinDerivationPath(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, NWString* _Nonnull derivationPath);

/// Saves the key to a file.
NW_EXPORT_METHOD
bool NWStoredKeyStore(struct NWStoredKey* _Nonnull key, NWString* _Nonnull path);

/// Decrypts the private key.
NW_EXPORT_METHOD
NWData* _Nullable NWStoredKeyDecryptPrivateKey(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password);

/// Decrypts the mnemonic phrase.
NW_EXPORT_METHOD
NWString* _Nullable NWStoredKeyDecryptMnemonic(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password);

/// Returns the private key for a specific coin.  Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWPrivateKey* _Nullable NWStoredKeyPrivateKey(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, NWData* _Nonnull password);

/// Decrypts and returns the HD Wallet for mnemonic phrase keys.  Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWHDWallet* _Nullable NWStoredKeyWallet(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password);

/// Exports the key as JSON
NW_EXPORT_METHOD
NWData* _Nullable NWStoredKeyExportJSON(struct NWStoredKey* _Nonnull key);

/// Fills in empty and invalid addresses.
///
/// This method needs the encryption password to re-derive addresses from private keys.
/// @returns `false` if the password is incorrect.
NW_EXPORT_METHOD
bool NWStoredKeyFixAddresses(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password);

/// Retrieve stored key encoding parameters, as JSON string.
NW_EXPORT_PROPERTY
NWString* _Nullable NWStoredKeyEncryptionParameters(struct NWStoredKey* _Nonnull key);

NW_EXTERN_C_END
