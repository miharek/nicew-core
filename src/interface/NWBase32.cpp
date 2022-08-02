//
// Created by Mihael Rek on 02/08/2022.
//

#include "NiceWCore/NWBase32.h"

#include "../Base32.h"

#include "string"

using namespace NW;

NWData* NWBase32DecodeWithAlphabet(NWString* _Nonnull string, NWString* _Nonnull alphabet) {
    Data decodedOut;
    auto cppString = *reinterpret_cast<const std::string*>(string);
    const char* alphabetRaw = nullptr;
    if (NWStringSize(alphabet) > 0) {
        alphabetRaw = NWStringUTF8Bytes(alphabet);
    }
    auto result = Base32::decode(cppString, decodedOut, alphabetRaw);
    return result ? NWDataCreateWithData(&decodedOut) : nullptr;
}

NWData *_Nullable NWBase32Decode(NWString* _Nonnull string) {
    std::string empty;
    return NWBase32DecodeWithAlphabet(string, &empty);
}

NWString *_Nonnull NWBase32EncodeWithAlphabet(NWData* _Nonnull data, NWString* _Nonnull alphabet) {
    auto cppData = *reinterpret_cast<const Data*>(data);
    const char* alphabetRaw = nullptr;
    if (NWStringSize(alphabet) > 0) {
        alphabetRaw = NWStringUTF8Bytes(alphabet);
    }
    auto result = Base32::encode(cppData, alphabetRaw);
    return NWStringCreateWithUTF8Bytes(result.c_str());
}

NWString *_Nonnull NWBase32Encode(NWData *_Nonnull data) {
    std::string empty;
    return NWBase32EncodeWithAlphabet(data, &empty);
}