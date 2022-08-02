//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWBase64.h>

#include "../Base64.h"

#include <string>

using namespace NW;

NWData* _Nullable NWBase64Decode(NWString* _Nonnull string) {
    auto cppString = *reinterpret_cast<const std::string*>(string);
    Data decodedOut = Base64::decode(cppString);
    return NWDataCreateWithData(&decodedOut);
}

NWData* _Nullable NWBase64DecodeUrl(NWString* _Nonnull string) {
    auto cppString = *reinterpret_cast<const std::string*>(string);
    Data decodedOut = Base64::decodeBase64Url(cppString);
    return NWDataCreateWithData(&decodedOut);
}

NWString *_Nonnull NWBase64Encode(NWData *_Nonnull data) {
    auto cppData = *reinterpret_cast<const Data*>(data);
    auto result = Base64::encode(cppData);
    return NWStringCreateWithUTF8Bytes(result.c_str());
}

NWString *_Nonnull NWBase64EncodeUrl(NWData *_Nonnull data) {
    auto cppData = *reinterpret_cast<const Data*>(data);
    auto result = Base64::encodeBase64Url(cppData);
    return NWStringCreateWithUTF8Bytes(result.c_str());
}