//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWBitcoinScript.h>

#include "../Bitcoin/Script.h"
#include "../Bitcoin/SigHashType.h"

#include <iterator>

using namespace NW::Bitcoin;

struct NWBitcoinScript *_Nonnull NWBitcoinScriptCreate() {
    auto* script = new NWBitcoinScript{};
    return script;
}

struct NWBitcoinScript *NWBitcoinScriptCreateWithData(NWData *data) {
    auto* script = new NWBitcoinScript{};
    script->impl.bytes.resize(NWDataSize(data));
    NWDataCopyBytes(data, 0, NWDataSize(data), script->impl.bytes.data());
    return script;
}

struct NWBitcoinScript *_Nonnull NWBitcoinScriptCreateWithBytes(uint8_t *_Nonnull bytes, size_t size) {
auto* script = new NWBitcoinScript{};
std::copy(bytes, bytes + size, std::back_inserter(script->impl.bytes));
return script;
}

struct NWBitcoinScript *NWBitcoinScriptCreateCopy(const struct NWBitcoinScript *script) {
    auto* newScript = new NWBitcoinScript{};
    newScript->impl.bytes = script->impl.bytes;
    return newScript;
}

void NWBitcoinScriptDelete(struct NWBitcoinScript *script) {
    delete script;
}

size_t NWBitcoinScriptSize(const struct NWBitcoinScript *script) {
    return script->impl.bytes.size();
}

NWData *NWBitcoinScriptData(const struct NWBitcoinScript *script) {
    return NWDataCreateWithBytes(&script->impl.bytes[0], script->impl.bytes.size());
}

NWData *NWBitcoinScriptScriptHash(const struct NWBitcoinScript *_Nonnull script) {
    auto result = script->impl.hash();
    return NWDataCreateWithBytes(result.data(), result.size());
}

bool NWBitcoinScriptIsPayToScriptHash(const struct NWBitcoinScript *script) {
    return script->impl.isPayToScriptHash();
}

bool NWBitcoinScriptIsPayToWitnessScriptHash(const struct NWBitcoinScript *script) {
    return script->impl.isPayToWitnessScriptHash();
}

bool NWBitcoinScriptIsPayToWitnessPublicKeyHash(const struct NWBitcoinScript *script) {
    return script->impl.isPayToWitnessPublicKeyHash();
}

bool NWBitcoinScriptIsWitnessProgram(const struct NWBitcoinScript *script) {
    return script->impl.isWitnessProgram();
}

bool NWBitcoinScriptEqual(const struct NWBitcoinScript *_Nonnull lhs, const struct NWBitcoinScript *_Nonnull rhs) {
    return lhs->impl.bytes == rhs->impl.bytes;
}

NWData *NWBitcoinScriptMatchPayToPubkey(const struct NWBitcoinScript *script) {
    std::vector<uint8_t> data;
    if (script->impl.matchPayToPublicKey(data)) {
        return NWDataCreateWithBytes(data.data(), data.size());
    }
    return nullptr;
}

NWData *NWBitcoinScriptMatchPayToPubkeyHash(const struct NWBitcoinScript *script) {
    std::vector<uint8_t> data;
    if (script->impl.matchPayToPublicKeyHash(data)) {
        return NWDataCreateWithBytes(data.data(), data.size());
    }
    return nullptr;
}

NWData *_Nullable NWBitcoinScriptMatchPayToScriptHash(const struct NWBitcoinScript *script) {
    std::vector<uint8_t> data;
    if (script->impl.matchPayToScriptHash(data)) {
        return NWDataCreateWithBytes(data.data(), data.size());
    }
    return nullptr;
}

NWData *_Nullable NWBitcoinScriptMatchPayToWitnessPublicKeyHash(const struct NWBitcoinScript *script) {
    std::vector<uint8_t> data;
    if (script->impl.matchPayToWitnessPublicKeyHash(data)) {
        return NWDataCreateWithBytes(data.data(), data.size());
    }
    return nullptr;
}

NWData *_Nullable NWBitcoinScriptMatchPayToWitnessScriptHash(const struct NWBitcoinScript *script) {
    std::vector<uint8_t> data;
    if (script->impl.matchPayToWitnessScriptHash(data)) {
        return NWDataCreateWithBytes(data.data(), data.size());
    }
    return nullptr;
}

NWData *NWBitcoinScriptEncode(const struct NWBitcoinScript *script) {
    auto result = std::vector<uint8_t>{};
    script->impl.encode(result);
    return NWDataCreateWithBytes(result.data(), result.size());
}

struct NWBitcoinScript *NWBitcoinScriptBuildPayToPublicKey(NWData *pubkey) {
    auto* v = reinterpret_cast<const std::vector<uint8_t>*>(pubkey);
    auto script = Script::buildPayToPublicKey(*v);
    return new NWBitcoinScript{ .impl = script };
}

struct NWBitcoinScript *NWBitcoinScriptBuildPayToPublicKeyHash(NWData *hash) {
    auto* v = reinterpret_cast<const std::vector<uint8_t>*>(hash);
    auto script = Script::buildPayToPublicKeyHash(*v);
    return new NWBitcoinScript{ .impl = script };
}

struct NWBitcoinScript *NWBitcoinScriptBuildPayToScriptHash(NWData *scriptHash) {
    auto* v = reinterpret_cast<const std::vector<uint8_t>*>(scriptHash);
    auto script = Script::buildPayToScriptHash(*v);
    return new NWBitcoinScript{ .impl = script };
}

struct NWBitcoinScript *NWBitcoinScriptBuildPayToWitnessPubkeyHash(NWData *hash) {
    auto* v = reinterpret_cast<const std::vector<uint8_t>*>(hash);
    auto script = Script::buildPayToWitnessPublicKeyHash(*v);
    return new NWBitcoinScript{ .impl = script };
}

struct NWBitcoinScript *NWBitcoinScriptBuildPayToWitnessScriptHash(NWData *scriptHash) {
    auto* v = reinterpret_cast<const std::vector<uint8_t>*>(scriptHash);
    auto script = Script::buildPayToWitnessScriptHash(*v);
    return new NWBitcoinScript{ .impl = script };
}

struct NWBitcoinScript *_Nonnull NWBitcoinScriptLockScriptForAddress(NWString *_Nonnull address, enum NWCoinType coin) {
auto* s = reinterpret_cast<const std::string*>(address);
auto script = Script::lockScriptForAddress(*s, coin);
return new NWBitcoinScript{ .impl = script };
}

uint32_t NWBitcoinScriptHashTypeForCoin(enum NWCoinType coinType) {
    return NW::Bitcoin::hashTypeForCoin(coinType);
}
