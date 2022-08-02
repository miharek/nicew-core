//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWAES.h>

#include <../../src/Encrypt.h>

using namespace NW;

NWData *_Nullable NWAESEncryptCBC(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv, enum NWAESPaddingMode mode) {
    try {
        Data encrypted = Encrypt::AESCBCEncrypt(*((Data*)key), *((Data*)data), *((Data*)iv), mode);
        return NWDataCreateWithData(&encrypted);
    } catch (...) {
        return nullptr;
    }
}

NWData *_Nullable NWAESDecryptCBC(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv, enum NWAESPaddingMode mode) {
    try {
        Data decrypted = Encrypt::AESCBCDecrypt(*((Data*)key), *((Data*)data), *((Data*)iv), mode);
        return NWDataCreateWithData(&decrypted);
    } catch (...) {
        return nullptr;
    }
}

NWData *_Nullable NWAESEncryptCTR(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv) {
    try {
        Data encrypted = Encrypt::AESCTREncrypt(*((Data*)key), *((Data*)data), *((Data*)iv));
        return NWDataCreateWithData(&encrypted);
    } catch (...) {
        return nullptr;
    }
}

NWData *_Nullable NWAESDecryptCTR(NWData *_Nonnull key, NWData *_Nonnull data, NWData *_Nonnull iv) {
    try {
        Data decrypted = Encrypt::AESCTRDecrypt(*((Data*)key), *((Data*)data), *((Data*)iv));
        return NWDataCreateWithData(&decrypted);
    } catch (...) {
        return nullptr;
    }
}
