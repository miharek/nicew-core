//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWEthereumAbi.h>
#include <NiceWCore/NWEthereumAbiFunction.h>

#include "Data.h"
#include "Ethereum/ABI.h"
#include "Ethereum/ContractCall.h"
#include "HexCoding.h"
#include "uint256.h"

#include <cassert>
#include <string>
#include <vector>

using namespace NW::Ethereum::ABI;
using namespace NW::Ethereum;
using namespace NW;


NWData* _Nonnull NWEthereumAbiEncode(struct NWEthereumAbiFunction* _Nonnull func_in) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data encoded;
    function.encode(encoded);
    return NWDataCreateWithData(&encoded);
}

bool NWEthereumAbiDecodeOutput(struct NWEthereumAbiFunction* _Nonnull func_in,
                               NWData* _Nonnull encoded) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;
    assert(encoded != nullptr);
    Data encData = data(NWDataBytes(encoded), NWDataSize(encoded));

    size_t offset = 0;
    return function.decodeOutput(encData, offset);
}

NWString* _Nullable NWEthereumAbiDecodeCall(NWData* _Nonnull callData, NWString* _Nonnull abiString) {
const Data& call = *(reinterpret_cast<const Data*>(callData));
const auto& jsonString = *reinterpret_cast<const std::string*>(abiString);
try {
auto abi = nlohmann::json::parse(jsonString);
auto string = decodeCall(call, abi);
if (!string.has_value()) {
return nullptr;
}
return NWStringCreateWithUTF8Bytes(string->c_str());
}
catch(...) {
return nullptr;
}
}

NWData* _Nonnull NWEthereumAbiEncodeTyped(NWString* _Nonnull messageJson) {
Data data;
try {
data = ParamStruct::hashStructJson(NWStringUTF8Bytes(messageJson));
} catch (...) {} // return empty
return NWDataCreateWithBytes(data.data(), data.size());
}
