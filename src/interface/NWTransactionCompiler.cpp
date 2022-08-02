//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWTransactionCompiler.h>

#include "TransactionCompiler.h"
#include "Data.h"
#include "uint256.h"

#include <cassert>

using namespace NW;


NWData *_Nonnull NWTransactionCompilerBuildInput(enum NWCoinType coinType, NWString *_Nonnull from, NWString *_Nonnull to, NWString *_Nonnull amount, NWString *_Nonnull asset, NWString *_Nonnull memo, NWString *_Nonnull chainId) {
    Data result;
    try {
        result = TransactionCompiler::buildInput(
                coinType,
                std::string(NWStringUTF8Bytes(from)),
                std::string(NWStringUTF8Bytes(to)),
                std::string(NWStringUTF8Bytes(amount)),
                std::string(NWStringUTF8Bytes(asset)),
                std::string(NWStringUTF8Bytes(memo)),
                std::string(NWStringUTF8Bytes(chainId))
        );
    } catch (...) {} // return empty
    return NWDataCreateWithBytes(result.data(), result.size());
}

std::vector<Data> createFromNWDataVector(const struct NWDataVector* _Nonnull dataVector) {
    std::vector<Data> ret;
    const auto n = NWDataVectorSize(dataVector);
    for (auto i = 0ul; i < n; ++i) {
        auto elem = NWDataVectorGet(dataVector, i);
        ret.push_back(*(static_cast<const Data*>(elem)));
        NWDataDelete(elem);
    }
    return ret;
}

NWData *_Nonnull NWTransactionCompilerPreImageHashes(enum NWCoinType coinType, NWData *_Nonnull txInputData) {
    Data result;
    try {
        assert(txInputData != nullptr);
        const Data inputData = data(NWDataBytes(txInputData), NWDataSize(txInputData));

        result = TransactionCompiler::preImageHashes(coinType, inputData);
    } catch (...) {} // return empty
    return NWDataCreateWithBytes(result.data(), result.size());
}

NWData *_Nonnull NWTransactionCompilerCompileWithSignatures(enum NWCoinType coinType, NWData *_Nonnull txInputData, const struct NWDataVector *_Nonnull signatures, const struct NWDataVector *_Nonnull publicKeys) {
    Data result;
    try {
        assert(txInputData != nullptr);
        const Data inputData = data(NWDataBytes(txInputData), NWDataSize(txInputData));
        assert(signatures != nullptr);
        const auto signaturesVec = createFromNWDataVector(signatures);
        assert(publicKeys != nullptr);
        const auto publicKeysVec = createFromNWDataVector(publicKeys);

        result  = TransactionCompiler::compileWithSignatures(coinType, inputData, signaturesVec, publicKeysVec);
    } catch (...) {} // return empty
    return NWDataCreateWithBytes(result.data(), result.size());
}
