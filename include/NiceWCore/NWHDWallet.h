//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWCoinType.h"
#include "NWCurve.h"
#include "NWData.h"
#include "NWHDVersion.h"
#include "NWDerivation.h"
#include "NWPrivateKey.h"
#include "NWPublicKey.h"
#include "NWPurpose.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_CLASS
struct NWHDWallet;

/// NWHDWalletIsValid has been deprecated; use NWMnemonicIsValid().

/// Creates a new HDWallet with a new random mnemonic with the provided strength in bits.
/// Null is returned on invalid strength. Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWHDWallet *_Nullable NWHDWalletCreate(int strength, NWString *_Nonnull passphrase);

/// Creates an HDWallet from a valid BIP39 English mnemonic and a passphrase.
/// Null is returned on invalid mnemonic. Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWHDWallet *_Nullable NWHDWalletCreateWithMnemonic(NWString *_Nonnull mnemonic, NWString *_Nonnull passphrase);

/// Creates an HDWallet from a BIP39 mnemonic, a passphrase and validation flag.
/// Null is returned on invalid mnemonic. Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWHDWallet *_Nullable NWHDWalletCreateWithMnemonicCheck(NWString *_Nonnull mnemonic, NWString *_Nonnull passphrase, bool check);

/// Creates an HDWallet from entropy (corresponding to a mnemonic).
/// Null is returned on invalid input. Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWHDWallet *_Nullable NWHDWalletCreateWithEntropy(NWData *_Nonnull entropy, NWString *_Nonnull passphrase);

/// Deletes a wallet.
NW_EXPORT_METHOD
void NWHDWalletDelete(struct NWHDWallet *_Nonnull wallet);

/// Wallet seed.
NW_EXPORT_PROPERTY
NWData *_Nonnull NWHDWalletSeed(struct NWHDWallet *_Nonnull wallet);

// Wallet Mnemonic
NW_EXPORT_PROPERTY
NWString *_Nonnull NWHDWalletMnemonic(struct NWHDWallet *_Nonnull wallet);

// Wallet entropy
NW_EXPORT_PROPERTY
NWData *_Nonnull NWHDWalletEntropy(struct NWHDWallet *_Nonnull wallet);

/// Returns master key. Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWPrivateKey *_Nonnull NWHDWalletGetMasterKey(struct NWHDWallet *_Nonnull wallet, enum NWCurve curve);

/// Generates the default private key for the specified coin. Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWPrivateKey *_Nonnull NWHDWalletGetKeyForCoin(struct NWHDWallet *_Nonnull wallet, enum NWCoinType coin);

/// Generates the default address for the specified coin (without exposing intermediary private key).
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetAddressForCoin(struct NWHDWallet *_Nonnull wallet, enum NWCoinType coin);

/// Generates the private key for the specified derivation path. Returned object needs to be deleted.
NW_EXPORT_METHOD
struct NWPrivateKey *_Nonnull NWHDWalletGetKey(struct NWHDWallet *_Nonnull wallet, enum NWCoinType coin, NWString *_Nonnull derivationPath);

/// Shortcut method to generate private key with the specified account/change/address (bip44 standard). Returned object needs to be deleted.
///
/// @see https://github.com/bitcoin/bips/blob/master/bip-0044.mediawiki
NW_EXPORT_METHOD
struct NWPrivateKey *_Nonnull NWHDWalletGetDerivedKey(struct NWHDWallet *_Nonnull wallet, enum NWCoinType coin, uint32_t account, uint32_t change, uint32_t address);

/// Returns the extended private key (for default 0 account). Returned object needs to be deleted.
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetExtendedPrivateKey(struct NWHDWallet *_Nonnull wallet, enum NWPurpose purpose, enum NWCoinType coin, enum NWHDVersion version);

/// Returns the exteded public key (for default 0 account). Returned object needs to be deleted.
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetExtendedPublicKey(struct NWHDWallet *_Nonnull wallet, enum NWPurpose purpose, enum NWCoinType coin, enum NWHDVersion version);

/// Returns the extended private key, for custom account. Returned object needs to be deleted.
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetExtendedPrivateKeyAccount(struct NWHDWallet *_Nonnull wallet, enum NWPurpose purpose, enum NWCoinType coin, enum NWDerivation derivation, enum NWHDVersion version, uint32_t account);

/// Returns the exteded public key, for custom account. Returned object needs to be deleted.
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetExtendedPublicKeyAccount(struct NWHDWallet *_Nonnull wallet, enum NWPurpose purpose, enum NWCoinType coin, enum NWDerivation derivation, enum NWHDVersion version, uint32_t account);

/// Returns the extended private key (for default 0 account with derivation). Returned object needs to be deleted.
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetExtendedPrivateKeyDerivation(struct NWHDWallet *_Nonnull wallet, enum NWPurpose purpose, enum NWCoinType coin, enum NWDerivation derivation, enum NWHDVersion version);

/// Returns the exteded public key (for default 0 account with derivation). Returned object needs to be deleted.
NW_EXPORT_METHOD
NWString *_Nonnull NWHDWalletGetExtendedPublicKeyDerivation(struct NWHDWallet *_Nonnull wallet, enum NWPurpose purpose, enum NWCoinType coin, enum NWDerivation derivation, enum NWHDVersion version);

/// Computes the public key from an exteded public key representation. Returned object needs to be deleted.
NW_EXPORT_STATIC_METHOD
struct NWPublicKey *_Nullable NWHDWalletGetPublicKeyFromExtended(NWString *_Nonnull extended, enum NWCoinType coin, NWString *_Nonnull derivationPath);

NW_EXTERN_C_END
