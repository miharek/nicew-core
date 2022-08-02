//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "Amount.h"
#include "Transaction.h"
#include "UTXO.h"
#include <NiceWCore/NWBitcoinSigHashType.h>
#include "../proto/Bitcoin.pb.h"

#include <string>
#include <vector>
#include <map>
#include <optional>

namespace NW::Bitcoin {

/// Input for signing, info of an unsigned transaction
class SigningInput {
public:
    // Hash type to use when signing
    enum NWBitcoinSigHashType hashType = NWBitcoinSigHashTypeAll;

    // Amount to send.  Transaction created will have this amount in its output, 
    // except when use_max_amount is set, in that case this amount is not relevant, maximum possible amount will be used (max avail less fee).
    // If amount is equal or more than the available amount, also max amount will be used.
    Amount amount = 0;

    // Transaction fee per byte
    Amount byteFee = 0;

    // Recipient's address
    std::string toAddress;

    // Change address
    std::string changeAddress;

    // Available private keys
    std::vector<PrivateKey> privateKeys;

    // Available redeem scripts indexed by script hash
    std::map<std::string, Script> scripts;

    // Available unspent transaction outputs
    UTXOs utxos;

    // If sending max amount
    bool useMaxAmount = false;

    // Coin type (forks)
    NWCoinType coinType = NWCoinTypeBitcoin;

    // Optional transaction plan
    std::optional<TransactionPlan> plan;

    Data outputOpReturn;

    uint32_t lockTime = 0;

public:
    SigningInput() = default;

    SigningInput(const Proto::SigningInput& input);
};

} // namespace NW::Bitcoin
