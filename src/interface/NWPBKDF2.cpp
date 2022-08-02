//
// Created by Mihael Rek on 02/08/2022.
//

#include <TrezorCrypto/memzero.h>
#include <TrezorCrypto/pbkdf2.h>
#include <NiceWCore/NWPBKDF2.h>

#include "Data.h"

using namespace NW;

NWData* _Nullable NWPBKDF2HmacSha256(NWData* _Nonnull password, NWData* _Nonnull salt,
        uint32_t iterations, uint32_t dkLen) {

Data key(dkLen);
int passLen = static_cast<int>(NWDataSize(password));
int saltLen = static_cast<int>(NWDataSize(salt));
pbkdf2_hmac_sha256(
        NWDataBytes(password),
        passLen,
        NWDataBytes(salt),
        saltLen,
        iterations,
        key.data(),
        dkLen
);
return NWDataCreateWithData(&key);
}

NWData* _Nullable NWPBKDF2HmacSha512(NWData* _Nonnull password, NWData* _Nonnull salt,
        uint32_t iterations, uint32_t dkLen) {
Data key(dkLen);
int passLen = static_cast<int>(NWDataSize(password));
int saltLen = static_cast<int>(NWDataSize(salt));
pbkdf2_hmac_sha512(
        NWDataBytes(password),
        passLen,
        NWDataBytes(salt),
        saltLen,
        iterations,
        key.data(),
        dkLen
);
return NWDataCreateWithData(&key);
}
