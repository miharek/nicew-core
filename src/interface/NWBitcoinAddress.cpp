//
// Created by Mihael Rek on 02/08/2022.
//

#include "../Base58.h"
#include "../Bitcoin/Address.h"

#include <TrezorCrypto/ecdsa.h>
#include <NiceWCore/NWBitcoinAddress.h>
#include <NiceWCore/NWPublicKey.h>

#include <cstring>

using namespace NW::Bitcoin;

bool NWBitcoinAddressEqual(struct NWBitcoinAddress *_Nonnull lhs, struct NWBitcoinAddress *_Nonnull rhs) {
    return lhs->impl == rhs->impl;
}

bool NWBitcoinAddressIsValid(NWData *_Nonnull data) {
    return NWDataSize(data) == Address::size;
}

bool NWBitcoinAddressIsValidString(NWString *_Nonnull string) {
    auto &s = *reinterpret_cast<const std::string *>(string);
    return Address::isValid(s);
}

struct NWBitcoinAddress *_Nullable NWBitcoinAddressCreateWithString(NWString *_Nonnull string) {
    auto& s = *reinterpret_cast<const std::string*>(string);
    try {
        return new NWBitcoinAddress{ Address(s) };
    } catch (...) {
        return nullptr;
    }
}

struct NWBitcoinAddress *_Nullable NWBitcoinAddressCreateWithData(NWData *_Nonnull data) {
    const auto& d = *reinterpret_cast<const NW::Data*>(data);
    try {
        return new NWBitcoinAddress{ Address(d) };
    } catch (...) {
        return nullptr;
    }
}

struct NWBitcoinAddress *_Nullable NWBitcoinAddressCreateWithPublicKey(struct NWPublicKey *_Nonnull publicKey, uint8_t prefix) {
    try {
        return new NWBitcoinAddress{ Address(publicKey->impl, prefix) };
    } catch (...) {
        return nullptr;
    }
}

void NWBitcoinAddressDelete(struct NWBitcoinAddress *_Nonnull address) {
    delete address;
}

NWString *_Nonnull

NWBitcoinAddressDescription(struct NWBitcoinAddress *_Nonnull address) {
    return NWStringCreateWithUTF8Bytes(address->impl.string().c_str());
}

uint8_t NWBitcoinAddressPrefix(struct NWBitcoinAddress *_Nonnull address) {
    return address->impl.bytes[0];
}

NWData *_Nonnull

NWBitcoinAddressKeyhash(struct NWBitcoinAddress *_Nonnull address) {
    return NWDataCreateWithBytes(address->impl.bytes.data() + 1, Address::size - 1);
}
