//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWData.h>
#include <NiceWCore/NWString.h>

#include <memory>

static inline char low_char(uint8_t v) {
    uint8_t lv = v & 0x0f;
    if (lv >= 0 && lv <= 9)
        return '0' + lv;
    if (lv >= 10)
        return 'a' + lv - 10;
    return 0;
}
static inline char high_char(uint8_t v) {
    uint8_t hv = (v & 0xf0) >> 4;
    if (hv >= 0 && hv <= 9)
        return '0' + hv;
    if (hv >= 10)
        return 'a' + hv - 10;
    return 0;
}

NWString *NWStringCreateWithHexData(NWData *_Nonnull data) {
    const size_t count = NWDataSize(data) * 2;
    char *bytes = (char *)malloc(count + 1);
    bytes[count] = 0;

    for (size_t i = 0; i < NWDataSize(data); i += 1) {
        bytes[2 * i] = high_char(NWDataGet(data, i));
        bytes[2 * i + 1] = low_char(NWDataGet(data, i));
    }

    const NWString *string = NWStringCreateWithUTF8Bytes(bytes);
    free(bytes);
    return string;
}