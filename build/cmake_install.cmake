# Install script for directory: /Users/miharek/Desktop/Magisterska/nicew-core

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for the subdirectory.
  include("/Users/miharek/Desktop/Magisterska/nicew-core/build/trezor-crypto/cmake_install.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/miharek/Desktop/Magisterska/nicew-core/build/libprotobuf.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libprotobuf.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libprotobuf.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libprotobuf.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/protobuf" TYPE FILE FILES
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/any.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/any.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/api.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/arena.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/arena_impl.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/arenastring.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/compiler/importer.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/compiler/parser.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/descriptor.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/descriptor.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/descriptor_database.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/duration.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/dynamic_message.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/empty.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/explicitly_constructed.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/extension_set.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/extension_set_inl.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/field_access_listener.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/field_mask.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_enum_reflection.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_enum_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_bases.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_reflection.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_table_driven.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_table_driven_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_tctable_decl.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_tctable_impl.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_tctable_impl.inc"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/generated_message_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/has_bits.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/implicit_weak_message.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/inlined_string_field.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/coded_stream.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/gzip_stream.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/io_win32.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/printer.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/strtod.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/tokenizer.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/zero_copy_stream.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/zero_copy_stream_impl.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/io/zero_copy_stream_impl_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map_entry.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map_entry_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map_field.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map_field_inl.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map_field_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/map_type_handler.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/message.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/message_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/metadata.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/metadata_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/parse_context.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/port.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/reflection.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/reflection_ops.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/repeated_field.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/repeated_ptr_field.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/service.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/source_context.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/struct.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/bytestream.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/callback.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/casts.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/common.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/hash.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/logging.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/macros.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/map_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/mutex.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/once.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/platform_macros.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/port.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/status.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/stl_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/stringpiece.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/strutil.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/stubs/template_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/text_format.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/timestamp.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/type.pb.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/unknown_field_set.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/delimited_message_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/field_comparator.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/field_mask_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/json_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/message_differencer.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/time_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/type_resolver.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/util/type_resolver_util.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/wire_format.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/wire_format_lite.h"
    "/Users/miharek/Desktop/Magisterska/nicew-core/build/local/src/protobuf/protobuf-3.19.2/src/google/protobuf/wrappers.pb.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/Users/miharek/Desktop/Magisterska/nicew-core/build/libNiceWCore.a")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libNiceWCore.a" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libNiceWCore.a")
    execute_process(COMMAND "/Library/Developer/CommandLineTools/usr/bin/ranlib" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libNiceWCore.a")
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/WalletCore" TYPE DIRECTORY FILES "/Users/miharek/Desktop/Magisterska/nicew-core/src/" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/Users/miharek/Desktop/Magisterska/nicew-core/include/")
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/Users/miharek/Desktop/Magisterska/nicew-core/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
