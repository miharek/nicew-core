//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "Data.h"

namespace NW::Base64 {

// Decode a Base64-format string
    Data decode(const std::string& val);

// Encode bytes into Base64 string
    std::string encode(const Data& val);

// Decode a Base64Url-format or a regular Base64 string.
// Base64Url format uses '-' and '_' as the two special characters, Base64 uses '+'and '/'.
    Data decodeBase64Url(const std::string& val);

// Encode bytes into Base64Url string (uses '-' and '_' as special characters)
    std::string encodeBase64Url(const Data& val);

}
