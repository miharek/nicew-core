//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once
#include "../proto/Bitcoin.pb.h"
#include "Data.h"
#include "CoinEntry.h"

#include <vector>
#include <optional>
#include <utility>

namespace NW::Bitcoin {

typedef std::vector<std::pair<Data, Data>> SignaturePubkeyList;

class Signer {
  public:
    Signer() = delete;

    /// Returns a transaction plan (utxo selection, fee estimation)
    static Proto::TransactionPlan plan(const Proto::SigningInput& input) noexcept;

    /// Signs a Proto::SigningInput transaction
    static Proto::SigningOutput sign(const Proto::SigningInput& input, std::optional<SignaturePubkeyList> optionalExternalSigs = {}) noexcept;

    /// Collect pre-image hashes to be signed
    static Proto::PreSigningOutput preImageHashes(const Proto::SigningInput& input) noexcept;
};

} // namespace NW::Bitcoin
