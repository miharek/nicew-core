//
// Created by Mihael Rek on 02/08/2022.
//

#include "SigningInput.h"

using namespace NW;
using namespace NW::Bitcoin;

SigningInput::SigningInput(const Proto::SigningInput& input) {
    hashType = static_cast<NWBitcoinSigHashType>(input.hash_type());
    amount = input.amount();
    byteFee = input.byte_fee();
    toAddress = input.to_address();
    changeAddress = input.change_address();
    for (auto&& key: input.private_key()) {
        privateKeys.emplace_back(key);
    }
    for (auto&& script: input.scripts()) {
        scripts[script.first] = Script(script.second.begin(), script.second.end());
    }
    for (auto&& u: input.utxo()) {
        utxos.emplace_back(u);
    }
    useMaxAmount = input.use_max_amount();
    coinType = static_cast<NWCoinType>(input.coin_type());
    if (input.has_plan()) {
        plan = TransactionPlan(input.plan());
    }
    outputOpReturn = data(input.output_op_return());
    lockTime = input.lock_time();
}
