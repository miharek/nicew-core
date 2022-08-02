//
// Created by Mihael Rek on 02/08/2022.
//

#include "FeeCalculator.h"

#include <cmath>

using namespace NW;

namespace NW::Bitcoin {

constexpr double gDecredBytesPerInput{166};
constexpr double gDecredBytesPerOutput{38};
constexpr double gDecredBytesBase{12};

int64_t LinearFeeCalculator::calculate(int64_t inputs, int64_t outputs,
                                       int64_t byteFee) const noexcept {
    const auto txsize =
        static_cast<int64_t>(std::ceil(bytesPerInput * static_cast<double>(inputs) +
                                       bytesPerOutput * static_cast<double>(outputs) + bytesBase));
    return txsize * byteFee;
}

int64_t LinearFeeCalculator::calculateSingleInput(int64_t byteFee) const noexcept {
    return static_cast<int64_t>(std::ceil(bytesPerInput)) * byteFee; // std::ceil(101.25) = 102
}

class DecredFeeCalculator : public LinearFeeCalculator {
public:
    constexpr DecredFeeCalculator() noexcept
        : LinearFeeCalculator(gDecredBytesPerInput, gDecredBytesPerOutput, gDecredBytesBase) {}
};

static constexpr DefaultFeeCalculator defaultFeeCalculator{};
static constexpr DecredFeeCalculator decredFeeCalculator{};
static constexpr SegwitFeeCalculator segwitFeeCalculator{};

const FeeCalculator& getFeeCalculator(NWCoinType coinType) noexcept {
    switch (coinType) {
    case NWCoinTypeDecred:
        return decredFeeCalculator;

    case NWCoinTypeBitcoin:
    case NWCoinTypeBitcoinGold:
    case NWCoinTypeDigiByte:
    case NWCoinTypeLitecoin:
    case NWCoinTypeViacoin:
    case NWCoinTypeGroestlcoin:
        return segwitFeeCalculator;

    default:
        return defaultFeeCalculator;
    }
}

} // namespace NW::Bitcoin
