//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWHash.h>
#include "../Hash.h"
#include "../Data.h"

#include "BinaryCoding.h"
#include <TrezorCrypto/blake2b.h>
#include <TrezorCrypto/ripemd160.h>
#include <TrezorCrypto/sha2.h>
#include <TrezorCrypto/sha3.h>

#include <array>

using namespace NW;

NWData* _Nonnull NWHashSHA1(NWData* _Nonnull data) {
const auto result = Hash::sha1(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithData(&result);
}

NWData* _Nonnull NWHashSHA256(NWData* _Nonnull data) {
const auto result = Hash::sha256(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA512(NWData* _Nonnull data) {
const auto result = Hash::sha512(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA512_256(NWData* _Nonnull data) {
const auto result = Hash::sha512_256(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashKeccak256(NWData* _Nonnull data) {
const auto result = Hash::keccak256(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashKeccak512(NWData* _Nonnull data) {
const auto result = Hash::keccak512(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA3_256(NWData* _Nonnull data) {
const auto result = Hash::sha3_256(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA3_512(NWData* _Nonnull data) {
const auto result = Hash::sha3_512(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashRIPEMD(NWData* _Nonnull data) {
const auto result = Hash::ripemd(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashBlake256(NWData* _Nonnull data) {
const auto result = Hash::blake256(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashBlake2b(NWData* _Nonnull data, size_t outlen) {
const auto result = Hash::blake2b(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data), outlen);
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashGroestl512(NWData* _Nonnull data) {
const auto result = Hash::groestl512(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA256SHA256(NWData* _Nonnull data) {
const auto result = Hash::sha256d(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA256RIPEMD(NWData* _Nonnull data) {
const auto result = Hash::sha256ripemd(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashSHA3_256RIPEMD(NWData* _Nonnull data) {
const auto result = Hash::sha3_256ripemd(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashBlake256Blake256(NWData* _Nonnull data) {
const auto result = Hash::blake256d(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashBlake256RIPEMD(NWData* _Nonnull data) {
const auto result = Hash::blake256ripemd(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}

NWData* _Nonnull NWHashGroestl512Groestl512(NWData* _Nonnull data) {
const auto result = Hash::groestl512d(reinterpret_cast<const byte*>(NWDataBytes(data)), NWDataSize(data));
return NWDataCreateWithBytes(result.data(), result.size());
}