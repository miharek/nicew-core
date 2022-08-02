cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

project(NiceWCore)

if (NOT ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang"))
    message(FATAL_ERROR "You should use clang compiler")
endif ()

if ("$ENV{PREFIX}" STREQUAL "")
    set(PREFIX "${CMAKE_SOURCE_DIR}/build/local")
else ()
    set(PREFIX "$ENV{PREFIX}")
endif ()

include(GNUInstallDirs)
include(cmake/StandardSettings.cmake)
include(cmake/CompilerWarnings.cmake)
include(cmake/StaticAnalyzers.cmake)
include(cmake/FindHostPackage.cmake)

add_library(${PROJECT_NAME}_INTERFACE INTERFACE)
target_include_directories(${PROJECT_NAME}_INTERFACE INTERFACE ${PREFIX}/include)
target_link_directories(${PROJECT_NAME}_INTERFACE INTERFACE ${PREFIX}/lib)
set_project_warnings(${PROJECT_NAME}_INTERFACE)

add_subdirectory(trezor-crypto)
if (NW_COMPILE_WASM)
    message(STATUS "Wasm build enabled")
    add_subdirectory(wasm)
endif ()

find_host_package(Boost REQUIRED)

include(ExternalProject)

# Dependencies
include(cmake/Protobuf.cmake)

# Source files
if (${ANDROID})
    message("Configuring for JNI")
    file(GLOB_RECURSE sources src/*.c src/*.cc src/*.cpp src/*.h jni/cpp/*.c jni/cpp/*.cpp jni/cpp/*.h jni/cpp/*.c)
    add_library(NiceWCore SHARED ${sources} ${PROTO_SRCS} ${PROTO_HDRS})
    find_library(log-lib log)
    target_link_libraries(NiceWCore PUBLIC ${PROJECT_NAME}_INTERFACE PRIVATE TrezorCrypto protobuf ${log-lib} Boost::boost)
else ()
    message("Configuring standalone")
    file(GLOB_RECURSE sources src/*.c src/*.cc src/*.cpp src/*.h)
    add_library(NiceWCore ${sources} ${PROTO_SRCS} ${PROTO_HDRS})

    target_link_libraries(NiceWCore PUBLIC ${PROJECT_NAME}_INTERFACE PRIVATE TrezorCrypto protobuf Boost::boost)
endif ()

if (NW_CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_enable_coverage(NiceWCore)
endif ()

if (NW_CLANG_ASAN)
    target_enable_asan(NiceWCore)
endif ()

# Define headers for this library. PUBLIC headers are used for compiling the
# library, and will be added to consumers' build paths.
target_include_directories(NiceWCore
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${CMAKE_CURRENT_SOURCE_DIR}/jni/cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/build/local/include
        )

if (NW_UNIT_TESTS)
    add_subdirectory(tests)
endif ()

if (NW_BUILD_EXAMPLES)
    add_subdirectory(walletconsole/lib)
    add_subdirectory(walletconsole)
endif()

if (NW_ENABLE_PVS_STUDIO)
    nw_add_pvs_studio_target(NiceWCore)
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/swift/cpp.xcconfig.in ${CMAKE_CURRENT_SOURCE_DIR}/swift/cpp.xcconfig @ONLY)

install(TARGETS NiceWCore
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        )

install(
        DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/src/
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/WalletCore
        FILES_MATCHING PATTERN "*.h"
)

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
