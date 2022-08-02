//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"
#include "NWString.h"
#include "NWData.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_CLASS
struct NWEthereumAbiFunction;

/// Creates a function object, with the given name and empty parameter list.  It must be deleted at the end.
NW_EXPORT_STATIC_METHOD
struct NWEthereumAbiFunction *_Nonnull NWEthereumAbiFunctionCreateWithString(NWString *_Nonnull name);

/// Deletes a function object created with a 'NWEthereumAbiFunctionCreateWithString' method.
NW_EXPORT_METHOD
void NWEthereumAbiFunctionDelete(struct NWEthereumAbiFunction *_Nonnull fn);

/// Return the function type signature, of the form "baz(int32,uint256)"
NW_EXPORT_METHOD
NWString *_Nonnull NWEthereumAbiFunctionGetType(struct NWEthereumAbiFunction *_Nonnull fn);

/// Methods for adding parameters of the given type (input or output).  
/// For output parameters (isOutput=true) a value has to be specified, although usually not needd.
/// Returns the index of the parameter (0-based).
NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamUInt8(struct NWEthereumAbiFunction *_Nonnull fn, uint8_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamUInt16(struct NWEthereumAbiFunction *_Nonnull fn, uint16_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamUInt32(struct NWEthereumAbiFunction *_Nonnull fn, uint32_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamUInt64(struct NWEthereumAbiFunction *_Nonnull fn, uint64_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamUInt256(struct NWEthereumAbiFunction *_Nonnull fn, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamUIntN(struct NWEthereumAbiFunction *_Nonnull fn, int bits, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamInt8(struct NWEthereumAbiFunction *_Nonnull fn, int8_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamInt16(struct NWEthereumAbiFunction *_Nonnull fn, int16_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamInt32(struct NWEthereumAbiFunction *_Nonnull fn, int32_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamInt64(struct NWEthereumAbiFunction *_Nonnull fn, int64_t val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamInt256(struct NWEthereumAbiFunction *_Nonnull fn, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamIntN(struct NWEthereumAbiFunction *_Nonnull fn, int bits, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamBool(struct NWEthereumAbiFunction *_Nonnull fn, bool val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamString(struct NWEthereumAbiFunction *_Nonnull fn, NWString *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamAddress(struct NWEthereumAbiFunction *_Nonnull fn, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamBytes(struct NWEthereumAbiFunction *_Nonnull fn, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamBytesFix(struct NWEthereumAbiFunction *_Nonnull fn, size_t size, NWData *_Nonnull val, bool isOutput);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddParamArray(struct NWEthereumAbiFunction *_Nonnull fn, bool isOutput);

/// Methods for accessing the value of an output or input parameter, of different types.
NW_EXPORT_METHOD
uint8_t NWEthereumAbiFunctionGetParamUInt8(struct NWEthereumAbiFunction *_Nonnull fn, int idx, bool isOutput);
NW_EXPORT_METHOD
uint64_t NWEthereumAbiFunctionGetParamUInt64(struct NWEthereumAbiFunction *_Nonnull fn, int idx, bool isOutput);
NW_EXPORT_METHOD
NWData *_Nonnull NWEthereumAbiFunctionGetParamUInt256(struct NWEthereumAbiFunction *_Nonnull fn, int idx, bool isOutput);
NW_EXPORT_METHOD
bool NWEthereumAbiFunctionGetParamBool(struct NWEthereumAbiFunction *_Nonnull fn, int idx, bool isOutput);
NW_EXPORT_METHOD
NWString *_Nonnull NWEthereumAbiFunctionGetParamString(struct NWEthereumAbiFunction *_Nonnull fn, int idx, bool isOutput);
NW_EXPORT_METHOD
NWData *_Nonnull NWEthereumAbiFunctionGetParamAddress(struct NWEthereumAbiFunction *_Nonnull fn, int idx, bool isOutput);

/// Methods for adding a parameter of the given type to a top-level input parameter array.  Returns the index of the parameter (0-based).
/// Note that nested ParamArrays are not possible through this API, could be done by using index paths like "1/0"
NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamUInt8(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, uint8_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamUInt16(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, uint16_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamUInt32(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, uint32_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamUInt64(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, uint64_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamUInt256(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, NWData *_Nonnull val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamUIntN(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, int bits, NWData *_Nonnull val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamInt8(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, int8_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamInt16(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, int16_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamInt32(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, int32_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamInt64(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, int64_t val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamInt256(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, NWData *_Nonnull val);

NW_EXPORT_METHOD
        NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamIntN(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, int bits, NWData *_Nonnull val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamBool(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, bool val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamString(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, NWString *_Nonnull val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamAddress(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, NWData *_Nonnull val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamBytes(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, NWData *_Nonnull val);

NW_EXPORT_METHOD
NW_METHOD_DISCARDABLE_RESULT
int NWEthereumAbiFunctionAddInArrayParamBytesFix(struct NWEthereumAbiFunction *_Nonnull fn, int arrayIdx, size_t size, NWData *_Nonnull val);

NW_EXTERN_C_END
