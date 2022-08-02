//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWEthereumAbiFunction.h>

#include "Ethereum/ABI.h"
#include "Data.h"
#include "HexCoding.h"
#include "../uint256.h"

#include <string>
#include <vector>
#include <cassert>

using namespace NW;
using namespace NW::Ethereum;
using namespace NW::Ethereum::ABI;

struct NWEthereumAbiFunction *_Nonnull NWEthereumAbiFunctionCreateWithString(NWString *_Nonnull name) {
auto func = Function(NWStringUTF8Bytes(name));
return new NWEthereumAbiFunction{ func };
}

void NWEthereumAbiFunctionDelete(struct NWEthereumAbiFunction *_Nonnull func_in) {
    assert(func_in != nullptr);
    delete func_in;
}

NWString *_Nonnull NWEthereumAbiFunctionGetType(struct NWEthereumAbiFunction *_Nonnull func_in) {
    assert(func_in != nullptr);
    auto function = func_in->impl;
    std::string sign = function.getType();
    return NWStringCreateWithUTF8Bytes(sign.c_str());
}

///// AddParam

int NWEthereumAbiFunctionAddParamUInt8(struct NWEthereumAbiFunction *_Nonnull func_in, uint8_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamUInt8>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamUInt16(struct NWEthereumAbiFunction *_Nonnull func_in, uint16_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamUInt16>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamUInt32(struct NWEthereumAbiFunction *_Nonnull func_in, uint32_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamUInt32>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamUInt64(struct NWEthereumAbiFunction *_Nonnull func_in, uint64_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamUInt64>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamUInt256(struct NWEthereumAbiFunction *_Nonnull func_in, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    uint256_t val2 = load(*static_cast<const Data*>(val));
    auto param = std::make_shared<ParamUInt256>(val2);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamUIntN(struct NWEthereumAbiFunction *_Nonnull func_in, int bits, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    uint256_t val2 = load(*static_cast<const Data*>(val));
    auto param = std::make_shared<ParamUIntN>(bits, val2);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamInt8(struct NWEthereumAbiFunction *_Nonnull func_in, int8_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamInt8>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamInt16(struct NWEthereumAbiFunction *_Nonnull func_in, int16_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamInt16>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamInt32(struct NWEthereumAbiFunction *_Nonnull func_in, int32_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamInt32>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamInt64(struct NWEthereumAbiFunction *_Nonnull func_in, int64_t val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamInt64>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamInt256(struct NWEthereumAbiFunction *_Nonnull func_in, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    int256_t val2 = ValueEncoder::int256FromUint256(load(*static_cast<const Data*>(val)));
    auto param = std::make_shared<ParamInt256>(val2);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamIntN(struct NWEthereumAbiFunction *_Nonnull func_in, int bits, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    int256_t val2 = ValueEncoder::int256FromUint256(load(*static_cast<const Data*>(val)));
    auto param = std::make_shared<ParamIntN>(bits, val2);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamBool(struct NWEthereumAbiFunction *_Nonnull func_in, bool val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamBool>(val);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamString(struct NWEthereumAbiFunction *_Nonnull func_in, NWString *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    auto param = std::make_shared<ParamString>(NWStringUTF8Bytes(val));
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamAddress(struct NWEthereumAbiFunction *_Nonnull func_in, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    Data data = NW::data(NWDataBytes(val), NWDataSize(val));
    auto param = std::make_shared<ParamAddress>(data);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamBytes(struct NWEthereumAbiFunction *_Nonnull func_in, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data data = NW::data(NWDataBytes(val), NWDataSize(val));
    auto param = std::make_shared<ParamByteArray>(data);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamBytesFix(struct NWEthereumAbiFunction *_Nonnull func_in, size_t count, NWData *_Nonnull val, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data data = NW::data(NWDataBytes(val), NWDataSize(val));
    auto param = std::make_shared<ParamByteArrayFix>(count, data);
    auto idx = function.addParam(param, isOutput);
    return idx;
}

int NWEthereumAbiFunctionAddParamArray(struct NWEthereumAbiFunction *_Nonnull func_in, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    auto param = std::make_shared<ParamArray>();
    auto idx = function.addParam(param, isOutput);
    return idx;
}

///// GetParam

uint8_t NWEthereumAbiFunctionGetParamUInt8(struct NWEthereumAbiFunction *_Nonnull func_in, int idx, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    std::shared_ptr<ParamBase> param;
    if (!function.getParam(idx, param, isOutput)) {
        return 0;
    }
    auto param2 = std::dynamic_pointer_cast<ParamUInt8>(param);
    if (param2 == nullptr) {
        return 0;
    }
    return param2->getVal();
}

uint64_t NWEthereumAbiFunctionGetParamUInt64(struct NWEthereumAbiFunction *_Nonnull func_in, int idx, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    std::shared_ptr<ParamBase> param;
    if (!function.getParam(idx, param, isOutput)) {
        return 0;
    }
    auto param2 = std::dynamic_pointer_cast<ParamUInt64>(param);
    if (param2 == nullptr) {
        return 0;
    }
    return param2->getVal();
}

NWData *_Nonnull NWEthereumAbiFunctionGetParamUInt256(struct NWEthereumAbiFunction *_Nonnull func_in, int idx, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    uint256_t val256 = 0;
    std::shared_ptr<ParamBase> param;
    if (!function.getParam(idx, param, isOutput)) {
        NW::Data valData = NW::store(val256);
        return NWDataCreateWithData(&valData);
    }
    auto param2 = std::dynamic_pointer_cast<ParamUInt256>(param);
    if (param2 == nullptr) {
        NW::Data valData = NW::store(val256);
        return NWDataCreateWithData(&valData);
    }
    val256 = param2->getVal();
    NW::Data valData = NW::store(val256);
    return NWDataCreateWithData(&valData);
}

bool NWEthereumAbiFunctionGetParamBool(struct NWEthereumAbiFunction *_Nonnull func_in, int idx, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    std::shared_ptr<ParamBase> param;
    if (!function.getParam(idx, param, isOutput)) {
        return false;
    }
    auto param2 = std::dynamic_pointer_cast<ParamBool>(param);
    if (param2 == nullptr) {
        return false;
    }
    return param2->getVal();
}

NWString *_Nonnull NWEthereumAbiFunctionGetParamString(struct NWEthereumAbiFunction *_Nonnull func_in, int idx, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    std::string valStr;
    std::shared_ptr<ParamBase> param;
    if (!function.getParam(idx, param, isOutput)) {
        return NWStringCreateWithUTF8Bytes(valStr.c_str());
    }
    auto param2 = std::dynamic_pointer_cast<ParamString>(param);
    if (param2 == nullptr) {
        return NWStringCreateWithUTF8Bytes(valStr.c_str());
    }
    valStr = param2->getVal();
    return NWStringCreateWithUTF8Bytes(valStr.c_str());
}

NWData *_Nonnull NWEthereumAbiFunctionGetParamAddress(struct NWEthereumAbiFunction *_Nonnull func_in, int idx, bool isOutput) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data valData;
    std::shared_ptr<ParamBase> param;
    if (!function.getParam(idx, param, isOutput)) {
        return NWDataCreateWithData(&valData);
    }
    auto param2 = std::dynamic_pointer_cast<ParamAddress>(param);
    if (param2 == nullptr) {
        return NWDataCreateWithData(&valData);
    }
    valData = param2->getData();
    return NWDataCreateWithData(&valData);
}

///// AddInArrayParam

int addInArrayParam(Function& function, int arrayIdx, const std::shared_ptr<ParamBase>& childParam) {
    std::shared_ptr<ParamBase> param;
    if (!function.getInParam(arrayIdx, param)) {
        return -1;
    }
    std::shared_ptr<ParamArray> paramArr = std::dynamic_pointer_cast<ParamArray>(param);
    if (paramArr == nullptr) {
        return -1; // not an array
    }
    return paramArr->addParam(childParam);
}

int NWEthereumAbiFunctionAddInArrayParamUInt8(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, uint8_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamUInt8>(val));
}

int NWEthereumAbiFunctionAddInArrayParamUInt16(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, uint16_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamUInt16>(val));
}

int NWEthereumAbiFunctionAddInArrayParamUInt32(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, uint32_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamUInt32>(val));
}

int NWEthereumAbiFunctionAddInArrayParamUInt64(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, uint64_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamUInt64>(val));
}

int NWEthereumAbiFunctionAddInArrayParamUInt256(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    uint256_t val2 = load(*static_cast<const Data*>(val));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamUInt256>(val2));
}

int NWEthereumAbiFunctionAddInArrayParamUIntN(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, int bits, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    uint256_t val2 = load(*static_cast<const Data*>(val));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamUIntN>(bits, val2));
}

int NWEthereumAbiFunctionAddInArrayParamInt8(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, int8_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamInt8>(val));
}

int NWEthereumAbiFunctionAddInArrayParamInt16(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, int16_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamInt16>(val));
}

int NWEthereumAbiFunctionAddInArrayParamInt32(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, int32_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamInt32>(val));
}

int NWEthereumAbiFunctionAddInArrayParamInt64(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, int64_t val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamInt64>(val));
}

int NWEthereumAbiFunctionAddInArrayParamInt256(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    int256_t val2 = ValueEncoder::int256FromUint256(load(*static_cast<const Data*>(val)));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamInt256>(val2));
}

int NWEthereumAbiFunctionAddInArrayParamIntN(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, int bits, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    int256_t val2 = ValueEncoder::int256FromUint256(load(*static_cast<const Data*>(val)));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamIntN>(bits, val2));
}

int NWEthereumAbiFunctionAddInArrayParamBool(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, bool val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    return addInArrayParam(function, arrayIdx, std::make_shared<ParamBool>(val));
}

int NWEthereumAbiFunctionAddInArrayParamString(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, NWString *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamString>(NWStringUTF8Bytes(val)));
}

int NWEthereumAbiFunctionAddInArrayParamAddress(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    assert(val != nullptr);
    Data data = NW::data(NWDataBytes(val), NWDataSize(val));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamAddress>(data));
}

int NWEthereumAbiFunctionAddInArrayParamBytes(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data data = NW::data(NWDataBytes(val), NWDataSize(val));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamByteArray>(data));
}

int NWEthereumAbiFunctionAddInArrayParamBytesFix(struct NWEthereumAbiFunction *_Nonnull func_in, int arrayIdx, size_t count, NWData *_Nonnull val) {
    assert(func_in != nullptr);
    Function& function = func_in->impl;

    Data data = NW::data(NWDataBytes(val), NWDataSize(val));
    return addInArrayParam(function, arrayIdx, std::make_shared<ParamByteArrayFix>(count, data));
}
