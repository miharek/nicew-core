//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWDataVector.h>

#include "Data.h"

#include <vector>
#include <cassert>

using namespace NW;


struct NWDataVector {
    std::vector<Data> impl;
};


struct NWDataVector *_Nonnull NWDataVectorCreate() {
    auto* obj = new struct NWDataVector();
    assert(obj != nullptr);
    return obj;
}

struct NWDataVector *_Nonnull NWDataVectorCreateWithData(NWData *_Nonnull data) {
auto* obj = new struct NWDataVector();
assert(obj != nullptr);

NWDataVectorAdd(obj, data);
return obj;
}

void NWDataVectorDelete(struct NWDataVector *_Nonnull dataVector) {
    delete dataVector;
}

void NWDataVectorAdd(struct NWDataVector *_Nonnull dataVector, NWData *_Nonnull data) {
    dataVector->impl.push_back(NW::data(NWDataBytes(data), NWDataSize(data)));
}

size_t NWDataVectorSize(const struct NWDataVector *_Nonnull dataVector) {
    return dataVector->impl.size();
}

NWData *_Nullable NWDataVectorGet(const struct NWDataVector *_Nonnull dataVector, size_t index) {
    if (index >= dataVector->impl.size()) {
        return nullptr;
    }
    auto& elem = dataVector->impl[index];
    return NWDataCreateWithBytes(elem.data(), elem.size());
}
