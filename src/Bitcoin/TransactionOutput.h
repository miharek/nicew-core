//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "Amount.h"
#include "Script.h"
#include "../Data.h"

#include <memory>

namespace NW::Bitcoin {

/// Bitcoin transaction output.
struct TransactionOutput {
    /// Transaction amount.
    Amount value;

    /// Usually contains the public key as a Bitcoin script setting up
    /// conditions to claim this output.
    Script script;

    /// Initializes an empty transaction output.
    TransactionOutput() = default;

    /// Initializes a transaction output with a value and a script.
    TransactionOutput(Amount value, Script script) : value(value), script(std::move(script)) {}

    /// Encodes the output into the provided buffer.
    void encode(Data& data) const;
};

} // namespace NW::Bitcoin
