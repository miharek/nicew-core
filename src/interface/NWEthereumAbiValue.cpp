//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWEthereumAbiValue.h>

#include <Ethereum/ABI/ValueEncoder.h>
#include <Ethereum/ABI/ValueDecoder.h>
#include <Data.h>

using namespace NW::Ethereum;
using namespace NW;


NWData* _Nonnull NWEthereumAbiValueEncodeBool(bool value) {
    Data data;
    ABI::ValueEncoder::encodeBool(value, data);
    return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeInt32(int32_t value) {
Data data;
ABI::ValueEncoder::encodeInt32(value, data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeUInt32(uint32_t value) {
Data data;
ABI::ValueEncoder::encodeUInt32(value, data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeInt256(NWData* _Nonnull value) {
Data data;
int256_t value256 = static_cast<int256_t>(NW::load(*reinterpret_cast<const Data*>(value)));
ABI::ValueEncoder::encodeInt256(value256, data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeUInt256(NWData* _Nonnull value) {
Data data;
uint256_t value256 = NW::load(*reinterpret_cast<const Data*>(value));
ABI::ValueEncoder::encodeUInt256(value256, data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeAddress(NWData* _Nonnull value) {
Data data;
ABI::ValueEncoder::encodeAddress(*reinterpret_cast<const Data*>(value), data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeString(NWString* _Nonnull value) {
Data data;
ABI::ValueEncoder::encodeString(NWStringUTF8Bytes(value), data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeBytes(NWData* _Nonnull value) {
Data data;
ABI::ValueEncoder::encodeBytes(*reinterpret_cast<const Data*>(value), data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWData* _Nonnull NWEthereumAbiValueEncodeBytesDyn(NWData* _Nonnull value) {
Data data;
ABI::ValueEncoder::encodeBytesDyn(*reinterpret_cast<const Data*>(value), data);
return NWDataCreateWithBytes(data.data(), data.size());
}

NWString* _Nonnull NWEthereumAbiValueDecodeUInt256(NWData* _Nonnull input) {
auto data = NW::data(NWDataBytes(input), NWDataSize(input));
auto decoded = Ethereum::ABI::ValueDecoder::decodeUInt256(data);
return NWStringCreateWithUTF8Bytes(NW::toString(decoded).c_str());
}

NWString* _Nonnull NWEthereumAbiValueDecodeValue(NWData* _Nonnull input, NWString* _Nonnull type) {
auto data = NW::data(NWDataBytes(input), NWDataSize(input));
auto value = Ethereum::ABI::ValueDecoder::decodeValue(data, NWStringUTF8Bytes(type));
return NWStringCreateWithUTF8Bytes(value.c_str());
}

NWString* _Nonnull NWEthereumAbiValueDecodeArray(NWData* _Nonnull input, NWString* _Nonnull type) {
auto data = NW::data(NWDataBytes(input), NWDataSize(input));
auto valueString = Ethereum::ABI::ValueDecoder::decodeValue(data, NWStringUTF8Bytes(type));
return NWStringCreateWithUTF8Bytes(valueString.c_str());
}
