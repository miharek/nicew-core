//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

typedef const void NWData;

/// Defines resizable string.
///
/// The implementation of these methods shhould be language-specific to minimize translation overhead.
/// For instane it should be a 'jstring' for Java and an 'NSString' for Swift.
/// Create allocates memory, the delete call should be called at the end to release memory.
typedef const void NWString;

/// Creates a string from a null-terminated UTF8 byte array. It must be deleted at the end.
NWString *_Nonnull NWStringCreateWithUTF8Bytes(const char *_Nonnull bytes) NW_VISIBILITY_DEFAULT;

/// Creates a string from a raw byte array and size.
NWString *_Nonnull NWStringCreateWithRawBytes(const uint8_t *_Nonnull bytes, size_t size) NW_VISIBILITY_DEFAULT;

/// Creates a hexadecimal string from block of data. It must be deleted at the end.
NWString *_Nonnull NWStringCreateWithHexData(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Returns the raw pointer to the string's UTF8 bytes (null-terminated).
char NWStringGet(NWString *_Nonnull string, size_t index) NW_VISIBILITY_DEFAULT;

/// Return the string size in bytes.
size_t NWStringSize(NWString *_Nonnull string) NW_VISIBILITY_DEFAULT;

/// Returns the raw pointer to the string's UTF8 bytes (null-terminated).
const char *_Nonnull NWStringUTF8Bytes(NWString *_Nonnull string) NW_VISIBILITY_DEFAULT;

/// Deletes a string created with a 'TWStringCreate*' method. After delete it must not be used (can seffault)!
void NWStringDelete(NWString *_Nonnull string) NW_VISIBILITY_DEFAULT;

/// Determines wether two string blocks are equal.
bool NWStringEqual(NWString *_Nonnull lhs, NWString *_Nonnull rhs) NW_VISIBILITY_DEFAULT;

NW_EXTERN_C_END
