//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "../Base58Address.h"
#include "../Data.h"
#include "../PublicKey.h"

#include <string>

namespace NW::Bitcoin {

/// Class for non-segwit P2PKH and P2SH addresses
class Address : public NW::Base58Address<21> {
  public:
    /// Initializes an address with a string representation.
    explicit Address(const std::string& string) : NW::Base58Address<21>(string) {}

    /// Initializes an address with a collection of bytes.
    explicit Address(const Data& data) : NW::Base58Address<21>(data) {}

    /// Initializes an address with a public key and a prefix.  Applicable for P2PKH addresses (but not P2SH).
    Address(const PublicKey& publicKey, byte prefix) : NW::Base58Address<21>(publicKey, {prefix}) {}
};

} // namespace NW::Bitcoin

/// Wrapper for C interface.
struct NWBitcoinAddress {
    NW::Bitcoin::Address impl;
};
