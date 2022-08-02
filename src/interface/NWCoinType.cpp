//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWCoinType.h>
#include <NiceWCore/NWHRP.h>

#include "../Coin.h"

enum NWBlockchain NWCoinTypeBlockchain(enum NWCoinType coin) {
    return NW::blockchain(coin);
}

enum NWPurpose NWCoinTypePurpose(enum NWCoinType coin) {
    return NW::purpose(coin);
}

enum NWCurve NWCoinTypeCurve(enum NWCoinType coin) {
    return NW::curve(coin);
}

enum NWHDVersion NWCoinTypeXpubVersion(enum NWCoinType coin) {
    return NW::xpubVersion(coin);
}

enum NWHDVersion NWCoinTypeXprvVersion(enum NWCoinType coin) {
    return NW::xprvVersion(coin);
}

bool NWCoinTypeValidate(enum NWCoinType coin, NWString *_Nonnull address) {
    return NW::validateAddress(coin, *reinterpret_cast<const std::string*>(address));
}

NWString *_Nonnull NWCoinTypeDerivationPath(enum NWCoinType coin) {
    const auto path = NW::derivationPath(coin);
    const auto string = path.string();
    return NWStringCreateWithUTF8Bytes(string.c_str());
}

NWString* NWCoinTypeDerivationPathWithDerivation(enum NWCoinType coin, enum NWDerivation derivation) {
    const auto path = NW::derivationPath(coin, derivation);
    const auto string = path.string();
    return NWStringCreateWithUTF8Bytes(string.c_str());
}

NWString *_Nonnull NWCoinTypeDeriveAddress(enum NWCoinType coin, struct NWPrivateKey *_Nonnull privateKey) {
    const auto string = NW::deriveAddress(coin, privateKey->impl);
    return NWStringCreateWithUTF8Bytes(string.c_str());
}

NWString *_Nonnull NWCoinTypeDeriveAddressFromPublicKey(enum NWCoinType coin, struct NWPublicKey *_Nonnull publicKey) {
    const auto string = NW::deriveAddress(coin, publicKey->impl);
    return NWStringCreateWithUTF8Bytes(string.c_str());
}

enum NWHRP NWCoinTypeHRP(enum NWCoinType coin) {
    return NW::hrp(coin);
}

uint8_t NWCoinTypeP2pkhPrefix(enum NWCoinType coin) {
    return NW::p2pkhPrefix(coin);
}

uint8_t NWCoinTypeP2shPrefix(enum NWCoinType coin) {
    return NW::p2shPrefix(coin);
}

uint8_t NWCoinTypeStaticPrefix(enum NWCoinType coin) {
    return NW::staticPrefix(coin);
}

NWString* _Nonnull NWCoinTypeChainId(enum NWCoinType coin) {
    return NWStringCreateWithUTF8Bytes(NW::chainId(coin));
}

uint32_t NWCoinTypeSlip44Id(enum NWCoinType coin) {
    return NW::slip44Id(coin);
}

enum NWPublicKeyType NWCoinTypePublicKeyType(enum NWCoinType coin) {
    return NW::publicKeyType(coin);
}
