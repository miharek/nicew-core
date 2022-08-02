//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "../CoinEntry.h"

namespace NW::Bitcoin {

/// Bitcoin entry dispatcher.
/// Note: do not put the implementation here (no matter how simple), to avoid having coin-specific
/// includes in this file
class Entry : public CoinEntry {
public:
    bool validateAddress(NWCoinType coin, const std::string& address, NW::byte p2pkh, NW::byte p2sh,
                         const char* hrp) const final;
    std::string normalizeAddress(NWCoinType coin, const std::string& address) const final;
    std::string deriveAddress(NWCoinType coin, const PublicKey& publicKey, NW::byte p2pkh,
                              const char* hrp) const final {
        return deriveAddress(coin, NWDerivationDefault, publicKey, p2pkh, hrp);
    }
    std::string deriveAddress(NWCoinType coin, NWDerivation derivation, const PublicKey& publicKey,
                              NW::byte p2pkh, const char* hrp) const final;
    Data addressToData(NWCoinType coin, const std::string& address) const;
    void sign(NWCoinType coin, const Data& dataIn, Data& dataOut) const final;
    void plan(NWCoinType coin, const Data& dataIn, Data& dataOut) const final;

    Data preImageHashes(NWCoinType coin, const Data& txInputData) const final;
    void compile(NWCoinType coin, const Data& txInputData, const std::vector<Data>& signatures,
                 const std::vector<PublicKey>& publicKeys, Data& dataOut) const final;
    // Note: buildTransactionInput is not implemented for Binance chain with UTXOs
};

} // namespace NW::Bitcoin
