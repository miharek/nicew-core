//
// Created by Mihael Rek on 02/08/2022.
//

#include "AESParameters.h"

#include "../HexCoding.h"

#include <TrezorCrypto/rand.h>

using namespace NW;
using namespace NW::Keystore;

AESParameters::AESParameters() {
    iv = Data(blockSize, 0);
    random_buffer(iv.data(), blockSize);
}

namespace CodingKeys {
static const auto iv = "iv";
} // namespace CodingKeys

/// Initializes `AESParameters` with a JSON object.
AESParameters::AESParameters(const nlohmann::json& json) {
    iv = parse_hex(json[CodingKeys::iv].get<std::string>());
}

/// Saves `this` as a JSON object.
nlohmann::json AESParameters::json() const {
    nlohmann::json j;
    j[CodingKeys::iv] = hex(iv);
    return j;
}
