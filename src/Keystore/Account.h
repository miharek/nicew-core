//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "../DerivationPath.h"
#include <NiceWCore/NWDerivation.h>

#include <nlohmann/json.hpp>
#include <string>

namespace NW::Keystore {

/// Account for a particular coin within a wallet.
class Account {
  public:
    /// Coin this account is for
    NWCoinType coin;

    /// Account public address
    std::string address;

    /// Account derivation. May be missing or unreliable in Json stored format.
    NWDerivation derivation = NWDerivationDefault;

    /// Account derivation path, only relevant for HD wallets; info only.
    DerivationPath derivationPath;

    /// Account public key in hex format.
    std::string publicKey;

    /// Extended public key, info only.
    std::string extendedPublicKey;

    Account() = default;
    Account(std::string address, NWCoinType coin, NWDerivation derivation, DerivationPath derivationPath, std::string publicKey, std::string extendedPublicKey)
        : coin(coin)
        , address(std::move(address))
        , derivation(derivation)
        , derivationPath(std::move(derivationPath))
        , publicKey(std::move(publicKey))
        , extendedPublicKey(std::move(extendedPublicKey)) {}

    /// Initializes `Account` with a JSON object.
    Account(const nlohmann::json& json);

    /// Saves `this` as a JSON object.
    nlohmann::json json() const;
};

} // namespace NW::Keystore

/// Wrapper for C interface.
struct NWAccount {
    NW::Keystore::Account impl;
};
