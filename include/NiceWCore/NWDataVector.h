//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWData.h"

NW_EXTERN_C_BEGIN

// A vector of NWData byte arrays
NW_EXPORT_CLASS
struct NWDataVector;

NW_EXPORT_STATIC_METHOD
struct NWDataVector *_Nonnull NWDataVectorCreate();

// Create with one element
NW_EXPORT_STATIC_METHOD
struct NWDataVector *_Nonnull NWDataVectorCreateWithData(NWData *_Nonnull data);

// Delete must be called at the end
NW_EXPORT_METHOD
void NWDataVectorDelete(struct NWDataVector *_Nonnull dataVector);

// Add an element to the vector. Element is cloned (will be deleted with the vector, but input parameter must be deleted on its own)
NW_EXPORT_METHOD
void NWDataVectorAdd(struct NWDataVector *_Nonnull dataVector, NWData *_Nonnull data);

// Retrieve the number of elements
NW_EXPORT_PROPERTY
size_t NWDataVectorSize(const struct NWDataVector *_Nonnull dataVector);

// Retrieve the n-th element. A clone is returned (must be freed).
NW_EXPORT_METHOD
NWData *_Nullable NWDataVectorGet(const struct NWDataVector *_Nonnull dataVector, size_t index);

NW_EXTERN_C_END