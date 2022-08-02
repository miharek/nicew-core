//
// Created by Mihael Rek on 31/07/2022.
//
#if !defined(NW_EXTERN_C_BEGIN)
#if defined(__cplusplus)
#define NW_EXTERN_C_BEGIN extern "C" {
#define NW_EXTERN_C_END   }
#else
#define NW_EXTERN_C_BEGIN
#define NW_EXTERN_C_END
#endif
#endif

// Marker for default visibility
#define NW_VISIBILITY_DEFAULT __attribute__((visibility("default")))

// Marker for exported classes
#define NW_EXPORT_CLASS

// Marker for exported structs
#define NW_EXPORT_STRUCT

// Marker for exported enums
#define NW_EXPORT_ENUM(type)

// Marker for exported functions
#define NW_EXPORT_FUNC extern

// Marker for exported methods
#define NW_EXPORT_METHOD extern

// Marker for exported properties
#define NW_EXPORT_PROPERTY extern

// Marker for exported static methods
#define NW_EXPORT_STATIC_METHOD extern

// Marker for exported static properties
#define NW_EXPORT_STATIC_PROPERTY extern

// Marker for discardable result (static) method
#define NW_METHOD_DISCARDABLE_RESULT

// Marker for Protobuf types to be serialized across the interface
#define PROTO(x) TWData *

#if __has_feature(assume_nonnull)
#define NW_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
#define NW_ASSUME_NONNULL_END   _Pragma("clang assume_nonnull end")
#else
#define NW_ASSUME_NONNULL_BEGIN
#define NW_ASSUME_NONNULL_END
#endif


#if !__has_feature(nullability)
#ifndef _Nullable
#define _Nullable
#endif
#ifndef _Nonnull
#define _Nonnull
#endif
#ifndef _Null_unspecified
#define _Null_unspecified
#endif
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>