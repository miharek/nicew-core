//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWCoinType.h>
#include <NiceWCore/NWAnyAddress.h>
#include <NiceWCore/NWPublicKey.h>


#include "../Coin.h"

using namespace NW;

struct NWAnyAddress {
    NWString* address;
    enum NWCoinType coin;
};

bool NWAnyAddressEqual(struct NWAnyAddress* _Nonnull lhs, struct NWAnyAddress* _Nonnull rhs) {
    return NWStringEqual(lhs->address, rhs->address) && lhs->coin == rhs->coin;
}

bool NWAnyAddressIsValid(NWString* _Nonnull string, enum NWCoinType coin) {
    const auto& address = *reinterpret_cast<const std::string*>(string);
    return NW::validateAddress(coin, address);
}

struct NWAnyAddress* _Nullable NWAnyAddressCreateWithString(NWString* _Nonnull string, enum NWCoinType coin) {
    const auto& address = *reinterpret_cast<const std::string*>(string);
    auto normalized = NW::normalizeAddress(coin, address);
    if (normalized.empty()) { return nullptr; }
    return new NWAnyAddress{NWStringCreateWithUTF8Bytes(normalized.c_str()), coin};
}

struct NWAnyAddress* _Nonnull NWAnyAddressCreateWithPublicKey(struct NWPublicKey* _Nonnull publicKey, enum NWCoinType coin) {
    auto address = NW::deriveAddress(coin, publicKey->impl);
    return new NWAnyAddress{NWStringCreateWithUTF8Bytes(address.c_str()), coin};
}

void NWAnyAddressDelete(struct NWAnyAddress* _Nonnull address) {
    NWStringDelete(address->address);
    delete address;
}

NWString* _Nonnull NWAnyAddressDescription(struct NWAnyAddress* _Nonnull address) {
    return NWStringCreateWithUTF8Bytes(NWStringUTF8Bytes(address->address));
}

enum NWCoinType NWAnyAddressCoin(struct NWAnyAddress* _Nonnull address) {
    return address->coin;
}

NWData* _Nonnull NWAnyAddressData(struct NWAnyAddress* _Nonnull address) {
    const auto& string = *reinterpret_cast<const std::string*>(address->address);
    Data data;
    try {
        data = NW::addressToData(address->coin, string);
    } catch (...) {}
    return NWDataCreateWithBytes(data.data(), data.size());
}
