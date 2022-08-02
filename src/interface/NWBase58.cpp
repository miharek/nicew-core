//
// Created by Mihael Rek on 02/08/2022.
//

#include "NiceWCore/NWBase58.h"

#include "../Base58.h"

#include "string"

using namespace NW;

NWString *_Nonnull NWBase58Encode(NWData *_Nonnull data) {
    const auto& d = *reinterpret_cast<const Data*>(data);
    const auto str = Base58::bitcoin.encodeCheck(d);
    return NWStringCreateWithUTF8Bytes(str.c_str());
}

NWString *_Nonnull NWBase58EncodeNoCheck(NWData *_Nonnull data) {
    auto& d = *reinterpret_cast<const Data*>(data);
    const auto encoded = Base58::bitcoin.encode(d);
    return NWStringCreateWithUTF8Bytes(encoded.c_str());
}

NWData *_Nullable NWBase58Decode(NWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    const auto decoded = Base58::bitcoin.decodeCheck(s);
    if (decoded.empty()) {
        return nullptr;
    }

    return NWDataCreateWithBytes(decoded.data(), decoded.size());
}

NWData *_Nullable NWBase58DecodeNoCheck(NWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    const auto decoded = Base58::bitcoin.decode(s);
    if (decoded.empty()) {
        return nullptr;
    }

    return NWDataCreateWithBytes(decoded.data(), decoded.size());
}