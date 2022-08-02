//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWString.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_STRUCT
struct NWMnemonic;

/// Determines whether a BIP39 English mnemonic phrase is valid.
NW_EXPORT_STATIC_METHOD
bool NWMnemonicIsValid(NWString *_Nonnull mnemonic);

/// Determines whether word is a valid BIP39 English menemonic word.
NW_EXPORT_STATIC_METHOD
bool NWMnemonicIsValidWord(NWString *_Nonnull word);

/// Return BIP39 English words that match the given prefix. A single string is returned, with space-separated list of words.
NW_EXPORT_STATIC_METHOD
NWString* _Nonnull NWMnemonicSuggest(NWString *_Nonnull prefix);

NW_EXTERN_C_END
