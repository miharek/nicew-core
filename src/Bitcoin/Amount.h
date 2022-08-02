//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include <cstdint>

namespace NW::Bitcoin {

/// Amount in satoshis (can be negative)
using Amount = int64_t;

/// One bitcoin in satoshis
inline constexpr Amount gCoin = 100000000;

/// Maxximum valid amount in satoshis.
inline constexpr Amount gMaxAmount = 21000000 * gCoin;

} // namespace NW::Bitcoin
