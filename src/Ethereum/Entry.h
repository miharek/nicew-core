// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "../CoinEntry.h"

namespace NW::Ethereum {

/// Entry point for Ethereum and Ethereum-fork coins.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific includes in this file
class Entry: public CoinEntry {
public:
    virtual bool validateAddress(NWCoinType coin, const std::string& address, NW::byte p2pkh, NW::byte p2sh, const char* hrp) const;
    virtual std::string normalizeAddress(NWCoinType coin, const std::string& address) const;
    virtual std::string deriveAddress(NWCoinType coin, const PublicKey& publicKey, NW::byte p2pkh, const char* hrp) const;
    virtual Data addressToData(NWCoinType coin, const std::string& address) const;
    virtual void sign(NWCoinType coin, const Data& dataIn, Data& dataOut) const;
    virtual bool supportsJSONSigning() const { return true; }
    virtual std::string signJSON(NWCoinType coin, const std::string& json, const Data& key) const;

    virtual Data preImageHashes(NWCoinType coin, const Data& txInputData) const;
    virtual void compile(NWCoinType coin, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& dataOut) const;
    virtual Data buildTransactionInput(NWCoinType coinType, const std::string& from, const std::string& to, const uint256_t& amount, const std::string& asset, const std::string& memo, const std::string& chainId) const;
};

} // namespace NW::Ethereum
