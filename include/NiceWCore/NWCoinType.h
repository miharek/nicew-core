//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWBlockchain.h"
#include "NWCurve.h"
#include "NWHDVersion.h"
#include "NWHRP.h"
#include "NWPrivateKey.h"
#include "NWPurpose.h"
#include "NWString.h"
#include "NWDerivation.h"

NW_EXTERN_C_BEGIN

/// Coin type for Level 2 of BIP44.
///
/// - SeeAlso: https://github.com/satoshilabs/slips/blob/master/slip-0044.md
NW_EXPORT_ENUM(uint32_t)
enum NWCoinType {
    NWCoinTypeAeternity = 457,
    NWCoinTypeAion = 425,
    NWCoinTypeBinance = 714,
    NWCoinTypeBitcoin = 0,
    NWCoinTypeBitcoinCash = 145,
    NWCoinTypeBitcoinGold = 156,
    NWCoinTypeCallisto = 820,
    NWCoinTypeCardano = 1815, // Note: Cardano Shelley testnet uses purpose 1852 (not 44) 1852/1815
    NWCoinTypeCosmos = 118,
    NWCoinTypeDash = 5,
    NWCoinTypeDecred = 42,
    NWCoinTypeDigiByte = 20,
    NWCoinTypeDogecoin = 3,
    NWCoinTypeEOS = 194,
    NWCoinTypeEthereum = 60,
    NWCoinTypeEthereumClassic = 61,
    NWCoinTypeFIO = 235,
    NWCoinTypeGoChain = 6060,
    NWCoinTypeGroestlcoin = 17,
    NWCoinTypeICON = 74,
    NWCoinTypeIoTeX = 304,
    NWCoinTypeKava = 459,
    NWCoinTypeKin = 2017,
    NWCoinTypeLitecoin = 2,
    NWCoinTypeMonacoin = 22,
    NWCoinTypeNebulas = 2718,
    NWCoinTypeNULS = 8964,
    NWCoinTypeNano = 165,
    NWCoinTypeNEAR = 397,
    NWCoinTypeNimiq = 242,
    NWCoinTypeOntology = 1024,
    NWCoinTypePOANeNWork = 178,
    NWCoinTypeQtum = 2301,
    NWCoinTypeXRP = 144,
    NWCoinTypeSolana = 501,
    NWCoinTypeStellar = 148,
    NWCoinTypeTezos = 1729,
    NWCoinTypeTheta = 500,
    NWCoinTypeThunderToken = 1001,
    NWCoinTypeNEO = 888,
    NWCoinTypeTomoChain = 889,
    NWCoinTypeTron = 195,
    NWCoinTypeVeChain = 818,
    NWCoinTypeViacoin = 14,
    NWCoinTypeWanchain = 5718350,
    NWCoinTypeZcash = 133,
    NWCoinTypeFiro = 136,
    NWCoinTypeZilliqa = 313,
    NWCoinTypeZelcash = 19167,
    NWCoinTypeRavencoin = 175,
    NWCoinTypeWaves = 5741564,
    NWCoinTypeTerra = 330, // see also TerraV2
    NWCoinTypeTerraV2 = 10000330, // see also Terra
    NWCoinTypeHarmony = 1023,
    NWCoinTypeAlgorand = 283,
    NWCoinTypeKusama = 434,
    NWCoinTypePolkadot = 354,
    NWCoinTypeFilecoin = 461,
    NWCoinTypeElrond = 508,
    NWCoinTypeBandChain = 494,
    NWCoinTypeSmartChainLegacy = 10000714,
    NWCoinTypeSmartChain = 20000714,
    NWCoinTypeOasis = 474,
    NWCoinTypePolygon = 966,
    NWCoinTypeTHORChain = 931,
    NWCoinTypeBluzelle = 483,
    NWCoinTypeOptimism = 10000070,
    NWCoinTypeArbitrum = 10042221,
    NWCoinTypeECOChain = 10000553,
    NWCoinTypeAvalancheCChain = 10009000,
    NWCoinTypeXDai = 10000100,
    NWCoinTypeFantom = 10000250,
    NWCoinTypeCryptoOrg = 394,
    NWCoinTypeCelo = 52752,
    NWCoinTypeRonin = 10002020,
    NWCoinTypeOsmosis = 10000118,
    NWCoinTypeECash = 899,
    NWCoinTypeCronosChain = 10000025,
    NWCoinTypeSmartBitcoinCash = 10000145,
    NWCoinTypeKuCoinCommunityChain = 10000321,
    NWCoinTypeBoba = 10000288,
    NWCoinTypeMetis = 1001088,
    NWCoinTypeAurora = 1323161554,
    NWCoinTypeEvmos = 10009001,
    NWCoinTypeNativeEvmos = 20009001,
    NWCoinTypeMoonriver = 10001285,
    NWCoinTypeMoonbeam = 10001284,
    NWCoinTypeKavaEvm = 10002222,
    NWCoinTypeKlaytn = 10008217,
    NWCoinTypeMeter = 18000,
    NWCoinTypeOKXChain = 996,
};

/// Returns the blockchain for a coin type.
NW_EXPORT_PROPERTY
enum NWBlockchain NWCoinTypeBlockchain(enum NWCoinType coin);

/// Returns the purpose for a coin type.
NW_EXPORT_PROPERTY
enum NWPurpose NWCoinTypePurpose(enum NWCoinType coin);

/// Returns the curve that should be used for a coin type.
NW_EXPORT_PROPERTY
enum NWCurve NWCoinTypeCurve(enum NWCoinType coin);

/// Returns the xpub HD version that should be used for a coin type.
NW_EXPORT_PROPERTY
enum NWHDVersion NWCoinTypeXpubVersion(enum NWCoinType coin);

/// Returns the xprv HD version that should be used for a coin type.
NW_EXPORT_PROPERTY
enum NWHDVersion NWCoinTypeXprvVersion(enum NWCoinType coin);

/// Validates an address string.
NW_EXPORT_METHOD
bool NWCoinTypeValidate(enum NWCoinType coin, NWString* _Nonnull address);

/// Returns the default derivation path for a particular coin.
NW_EXPORT_METHOD
NWString* _Nonnull NWCoinTypeDerivationPath(enum NWCoinType coin);

/// Returns the derivation path for a particular coin with the explicit given derivation.
NW_EXPORT_METHOD
NWString* _Nonnull NWCoinTypeDerivationPathWithDerivation(enum NWCoinType coin, enum NWDerivation derivation);

/// Derives the address for a particular coin from the private key.
NW_EXPORT_METHOD
NWString* _Nonnull NWCoinTypeDeriveAddress(enum NWCoinType coin,
                                                   struct NWPrivateKey* _Nonnull privateKey);

/// Derives the address for a particular coin from the public key.
NW_EXPORT_METHOD
NWString* _Nonnull NWCoinTypeDeriveAddressFromPublicKey(enum NWCoinType coin, struct NWPublicKey* _Nonnull publicKey);

/// HRP for this coin type
NW_EXPORT_PROPERTY
enum NWHRP NWCoinTypeHRP(enum NWCoinType coin);

/// P2PKH prefix for this coin type
NW_EXPORT_PROPERTY
uint8_t NWCoinTypeP2pkhPrefix(enum NWCoinType coin);

/// P2SH prefix for this coin type
NW_EXPORT_PROPERTY
uint8_t NWCoinTypeP2shPrefix(enum NWCoinType coin);

/// Static prefix for this coin type
NW_EXPORT_PROPERTY
uint8_t NWCoinTypeStaticPrefix(enum NWCoinType coin);

/// ChainID for this coin type.  Caller must free return object.
NW_EXPORT_PROPERTY
NWString* _Nonnull NWCoinTypeChainId(enum NWCoinType coin);

/// SLIP-0044 id for this coin type
NW_EXPORT_PROPERTY
uint32_t NWCoinTypeSlip44Id(enum NWCoinType coin);

/// public key type for this coin type
NW_EXPORT_PROPERTY
enum NWPublicKeyType NWCoinTypePublicKeyType(enum NWCoinType coin);

NW_EXTERN_C_END
