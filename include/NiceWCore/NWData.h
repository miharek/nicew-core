//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

typedef const void NWString;

/// Defines a resizable block of data.
/// The implementation of these methods should be language-specific to minimize overhead.
/// For instance it should be a 'jbyteArray' for Jaca and an 'NSData' for Swift.
typedef const void NWData;

/// Creates a block of data from a byte array.
NWData *_Nonnull NWDataCreateWithBytes(const uint8_t *_Nonnull bytes, size_t size) NW_VISIBILITY_DEFAULT;

/// Creates an uninitialized blovk of data with the provided size.
NWData *_Nonnull NWDataCreateWithSize(size_t size) NW_VISIBILITY_DEFAULT;

/// Creates a block of data by copyinh another block of data.
NWData *_Nonnull NWDataCreateWithData(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Creates a block of data from a hexadecimal string. Odd lenght is invalid
NWData *_Nullable NWDataCreateWithHexString(const NWString *_Nonnull hex) NW_VISIBILITY_DEFAULT;

///Returns the size in bytes
size_t  NWDataSize(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Returns the raw pointer to the contents of data.
uint8_t *_Nonnull NWDataBytes(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Returns the byte at the provided index.
uint8_t NWDataGet(NWDataSize *_Nonnull data, size_t index) NW_VISIBILITY_DEFAULT;

/// Sets the byte at the provided index.
void NWDataSet(NWData *_Nonnull data, size_t index, uint8_t byte) NW_VISIBILITY_DEFAULT;

/// Copies a range of bytes into the provided buffer.
void NWDataCopyBytes(NWData *_Nonnull data, size_t start, size_t size, const uint8_t *_Nonnull bytes) NW_VISIBILITY_DEFAULT;

/// Replaces a range of byres wuth the contents of the provided buffer.
void NWDataReplaceBytes(NWData *_Nonnull data, size_t start, size_t size, const uint8_t *_Nonnull bytes) NW_VISIBILITY_DEFAULT;

/// Appends data from a byte array.
void NWDataAppendBytes(NWData *_Nonnull data, const uint8_t *_Nonnull bytes, size_t size) NW_VISIBILITY_DEFAULT;

/// Appends a single byte
void NWDataAppendByte(NWData *_Nonnull data, uint8_t byte) NW_VISIBILITY_DEFAULT;

/// Appends a block of data.
void NWDataAppendData(NWData *_Nonnull data, NWData *_Nonnull append) NW_VISIBILITY_DEFAULT;

/// Reverses the bytes.
void NWDataReverse(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Sets all bytes to the given value.
void NWDataReset(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Deletes a block of data created with 'NWDataCreate*' method.
void NWDataDelete(NWData *_Nonnull data) NW_VISIBILITY_DEFAULT;

/// Determines wether two data blocks are equal.
bool NWDataEqual(NWData *_Nonnull lhs, NWData *_Nonnull rhs) NW_VISIBILITY_DEFAULT;

NW_EXTERN_C_END