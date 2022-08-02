//
// Created by Mihael Rek on 02/08/2022.
//

#include "NiceWCore/NWString.h"
#include "string"

NWString *_Nonnull NWStringCreateWithUTF8Bytes(const char *_Nonnull bytes) {
    auto *s = new std::string(bytes);
    return s;
}

NWString *_Nonnull NWStringCreateWithRawBytes(const uint8_t *_Nonnull bytes, size_t size) {
    auto* s = new std::string(bytes, bytes + size);
    return s;
}

size_t NWStringSize(NWString *_Nonnull string) {
    auto* s = reinterpret_cast<const std::string*>(string);
    return s->size();
}

char NWStringGet(NWString *_Nonnull string, size_t index) {
    auto* s = reinterpret_cast<const std::string*>(string);
    return (*s)[index];
}

const char *_Nonnull NWStringUTF8Bytes(TWString *_Nonnull string) {
    auto* s = reinterpret_cast<const std::string*>(string);
    return s->c_str();
}

void NWStringDelete(TWString *_Nonnull string) {
    auto* s = reinterpret_cast<const std::string*>(string);
    delete s;
}

bool NWStringEqual(TWString *_Nonnull lhs, TWString *_Nonnull rhs) {
    auto* lv = reinterpret_cast<const std::string*>(lhs);
    auto* rv = reinterpret_cast<const std::string*>(rhs);
    return *lv == *rv;
}
