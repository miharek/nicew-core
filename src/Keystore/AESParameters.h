//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "../Data.h"

#include <nlohmann/json.hpp>

namespace NW::Keystore {

// AES128 parameters.
struct AESParameters {
    static const std::size_t blockSize = 128 / 8;

    Data iv;

    /// Initializes `AESParameters` with a random `iv` for AES 128.
    AESParameters();

    /// Initializes `AESParameters` with a JSON object.
    AESParameters(const nlohmann::json& json);

    /// Saves `this` as a JSON object.
    nlohmann::json json() const;
};

} // namespace NW::Keystore
