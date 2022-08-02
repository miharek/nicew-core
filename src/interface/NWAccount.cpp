//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWAccount.h>

#include "../Keystore/Account.h"

using namespace NW;

struct NWAccount* _Nonnull NWAccountCreate(NWString* _Nonnull address, enum NWCoinType coin,
                                            enum NWDerivation derivation,
                                            NWString* _Nonnull derivationPath,
                                            NWString* _Nonnull publicKey,
                                            NWString* _Nonnull extendedPublicKey) {
    auto& addressString = *reinterpret_cast<const std::string*>(address);
    auto& derivationPathString = *reinterpret_cast<const std::string*>(derivationPath);
    auto& publicKeyString = *reinterpret_cast<const std::string*>(publicKey);
    auto& extendedPublicKeyString = *reinterpret_cast<const std::string*>(extendedPublicKey);
    const auto dp = DerivationPath(derivationPathString);
    return new NWAccount{
        Keystore::Account(addressString, coin, derivation, dp, publicKeyString, extendedPublicKeyString)
    };
}

void NWAccountDelete(struct NWAccount* _Nonnull account) {
    delete account;
}

NWString* _Nonnull NWAccountAddress(struct NWAccount* _Nonnull account) {
    return NWStringCreateWithUTF8Bytes(account->impl.address.c_str());
}

enum NWDerivation NWAccountDerivation(struct NWAccount* _Nonnull account) {
    return account->impl.derivation;
}

NWString* _Nonnull NWAccountDerivationPath(struct NWAccount* _Nonnull account) {
    return NWStringCreateWithUTF8Bytes(account->impl.derivationPath.string().c_str());
}

NWString* _Nonnull NWAccountPublicKey(struct NWAccount* _Nonnull account) {
    return NWStringCreateWithUTF8Bytes(account->impl.publicKey.c_str());
}

NWString* _Nonnull NWAccountExtendedPublicKey(struct NWAccount* _Nonnull account) {
    return NWStringCreateWithUTF8Bytes(account->impl.extendedPublicKey.c_str());
}

enum NWCoinType NWAccountCoin(struct NWAccount* _Nonnull account) {
    return account->impl.coin;
}
