//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWAnySigner.h>

#include "Coin.h"

using namespace NW;

NWData* _Nonnull NWAnySignerSign(NWData* _Nonnull data, enum NWCoinType coin) {
    const Data& dataIn = *(reinterpret_cast<const Data*>(data));
    Data dataOut;
    NW::anyCoinSign(coin, dataIn, dataOut);
    return NWDataCreateWithBytes(dataOut.data(), dataOut.size());
}

NWString *_Nonnull NWAnySignerSignJSON(NWString *_Nonnull json, NWData *_Nonnull key, enum NWCoinType coin) {
    const Data& keyData = *(reinterpret_cast<const Data*>(key));
    const std::string& jsonString = *(reinterpret_cast<const std::string*>(json));
    auto result = NW::anySignJSON(coin, jsonString, keyData);
    return NWStringCreateWithUTF8Bytes(result.c_str());
}
extern bool NWAnySignerSupportsJSON(enum NWCoinType coin) {
    return NW::supportsJSONSigning(coin);
}

NWData* _Nonnull NWAnySignerPlan(NWData* _Nonnull data, enum NWCoinType coin) {
    const Data& dataIn = *(reinterpret_cast<const Data*>(data));
    Data dataOut;
    NW::anyCoinPlan(coin, dataIn, dataOut);
    return NWDataCreateWithBytes(dataOut.data(), dataOut.size());
}