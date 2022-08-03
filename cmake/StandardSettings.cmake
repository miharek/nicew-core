#
# Default settings
#
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
set(CMAKE_OSX_DEPLOYMENT_TARGET "10.14" CACHE STRING "Minimum OS X deployment version" FORCE)

#
# IDE Settings
#
option(NW_IDE_CLION "Enable if your IDE is CLion" OFF)
option(NW_IDE_VSCODE "Enable if your IDE is VSCode" OFF)

#
# Static analyzers
#
# Currently supporting: Clang-Tidy, PVS-Studio.
option(NW_ENABLE_CLANG_TIDY "Enable static analysis with Clang-Tidy." OFF)
option(NW_ENABLE_PVS_STUDIO "Enable static analysis with PVS-Studio." OFF)

#
# Runtime analyzers
#
# Currently supporting: Clang ASAN.
option(NW_CLANG_ASAN "Enable ASAN dynamic address sanitizer" OFF)

#
# Specific platforms support
#
# Currently supporting: Wasm.
option(NW_COMPILE_WASM "Target Wasm" OFF)

#
# Coverage
#
option(NW_CODE_COVERAGE "Enable coverage reporting" OFF)

#
# Compiler warnings options
#
option(NW_WARNINGS_AS_ERRORS "Compiler Options as Error" OFF)

#
# Compilation Speed options
#
option(NW_ENABLE_CCACHE "Enable the usage of Ccache, in order to speed up rebuild times." ON)

if (NW_ENABLE_CCACHE)
    find_program(CCACHE_FOUND ccache)
    if (CCACHE_FOUND)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
        set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
        message(STATUS "ccache activated")
    endif ()
endif ()

#
# Tests/Examples options
#
option(NW_BUILD_EXAMPLES "Enable the examples builds of the project" ON)



