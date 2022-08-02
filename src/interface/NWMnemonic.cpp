//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWMnemonic.h>

#include "../Mnemonic.h"

using namespace NW;

bool NWMnemonicIsValid(NWString *_Nonnull mnemonic) {
    return Mnemonic::isValid(NWStringUTF8Bytes(mnemonic));
}

bool NWMnemonicIsValidWord(NWString *_Nonnull word) {
    return Mnemonic::isValidWord(NWStringUTF8Bytes(word));
}

NWString* _Nonnull NWMnemonicSuggest(NWString *_Nonnull prefix) {
auto result = Mnemonic::suggest(std::string(NWStringUTF8Bytes(prefix)));
return NWStringCreateWithUTF8Bytes(result.c_str());
}
