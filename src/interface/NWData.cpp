//
// Created by Mihael Rek on 02/08/2022.
//

#include "NiceWCore/NWData.h"
#include "NiceWCore/NWString.h"
#include "Data.h"
#include "HexCoding.h"
#include <algorithm>
#include <vector>

using namespace NW;

NWData *_Nonnull NWDataCreateWithBytes(const uint8_t *_Nonnull bytes, size_t size) {
    auto *data = new Data();
    data->reserve(size);
    std::copy(bytes, bytes + size, std::back_inserter(*data));
    return data;
}

NWData *_Nonnull NWDataCreateWithSize(size_t size) {
    auto* data = new Data(size, 0);
    return data;
}

NWData *_Nonnull NWDataCreateWithData(NWData *_Nonnull data) {
    auto* other = reinterpret_cast<const Data*>(data);
    auto* copy = new Data(*other);
    return copy;
}

NWData * NWDataCreateWithHexString(const NWString* hex) {
    if (hex == nullptr) { return nullptr; }
    Data data = parse_hex(std::string(NWStringUTF8Bytes(hex)));
    return NWDataCreateWithBytes(data.data(), data.size());
}

size_t NWDataSize(NWData *_Nonnull data) {
    auto* v = reinterpret_cast<const Data*>(data);
    return v->size();
}

uint8_t *_Nonnull NWDataBytes(NWData *_Nonnull data) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    return v->data();
}

uint8_t NWDataGet(NWData *_Nonnull data, size_t index) {
    auto* v = reinterpret_cast<const Data*>(data);
    return (*v)[index];
}

void NWDataSet(NWData *_Nonnull data, size_t index, uint8_t byte) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    (*v)[index] = byte;
}

void NWDataCopyBytes(NWData *_Nonnull data, size_t start, size_t size, uint8_t *_Nonnull output) {
    auto* v = reinterpret_cast<const Data*>(data);
    std::copy(std::begin(*v) + start, std::begin(*v) + start + size, output);
}

void NWDataReplaceBytes(NWData *_Nonnull data, size_t start, size_t size, const uint8_t *_Nonnull bytes) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    std::copy(bytes, bytes + size, std::begin(*v) + start);
}

void NWDataAppendBytes(NWData *_Nonnull data, const uint8_t *_Nonnull bytes, size_t size) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    for (auto i = 0ul; i < size; i += 1)
        v->push_back(bytes[i]);
}

void NWDataAppendByte(NWData *_Nonnull data, uint8_t byte) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    v->push_back(byte);
}

void NWDataAppendData(NWData *_Nonnull data, NWData *_Nonnull append) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    auto* av = reinterpret_cast<const Data*>(append);
    std::copy(av->begin(), av->end(), std::back_inserter(*v));
}

void NWDataReverse(NWData *_Nonnull data) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    std::reverse(std::begin(*v), std::end(*v));
}

void NWDataReset(NWData *_Nonnull data) {
    auto* v = const_cast<Data*>(reinterpret_cast<const Data*>(data));
    std::fill(std::begin(*v), std::end(*v), 0);
}

void NWDataDelete(NWData *_Nonnull data) {
    auto* v = reinterpret_cast<const Data*>(data);
    delete v;
}

bool NWDataEqual(NWData *_Nonnull lhs, NWData *_Nonnull rhs) {
    auto* lv = reinterpret_cast<const Data*>(lhs);
    auto* rv = reinterpret_cast<const Data*>(rhs);
    return *lv == *rv;
}
