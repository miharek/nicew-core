macro(target_enable_asan target)
    message("-- ASAN Enabled, Configuring...")
    target_compile_options(${target} PUBLIC
            $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:-fsanitize=address -fno-omit-frame-pointer>
            $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang>>:-fsanitize=address -fno-omit-frame-pointer>)
    target_link_options(${target} PUBLIC
            $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:-fsanitize=address -fno-omit-frame-pointer>
            $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang>>:-fsanitize=address -fno-omit-frame-pointer>)
endmacro()

macro(target_enable_coverage target)
    message(STATUS "Code coverage ON")
    # This option is used to compile and link code instrumented for coverage analysis.
    # The option is a synonym for -fprofile-arcs -ftest-coverage (when compiling) and -lgcov (when linking).
    # See the documentation for those options for more details.
    # https://gcc.gnu.org/onlinedocs/gcc-9.3.0/gcc/Instrumentation-Options.html
    if (NW_IDE_CLION)
        message(STATUS "Code coverage for Clion ON")
        target_compile_options(${target} PUBLIC
                $<$<AND:$<PLATFORM_ID:Linux>,$<CXX_COMPILER_ID:Clang>>:-fprofile-instr-generate -fcoverage-mapping>
                $<$<AND:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:Clang>>:-fprofile-instr-generate -fcoverage-mapping>
                $<$<AND:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:AppleClang>>:-fprofile-instr-generate -fcoverage-mapping>)
        target_link_options(${target} PUBLIC
                $<$<AND:$<PLATFORM_ID:Linux>,$<CXX_COMPILER_ID:Clang>>:-fprofile-instr-generate -fcoverage-mapping>
                $<$<AND:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:Clang>>:-fprofile-instr-generate -fcoverage-mapping>
                $<$<AND:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:AppleClang>>:-fprofile-instr-generate -fcoverage-mapping>)
    else()
        target_compile_options(${target} PUBLIC
                $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:--coverage>
                $<$<AND:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:AppleClang>>:--coverage>)
        target_link_options(${target} PUBLIC
                $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:--coverage>
                $<$<AND:$<PLATFORM_ID:Darwin>,$<CXX_COMPILER_ID:AppleClang>>:--coverage>)
    endif ()
endmacro()

add_library(nw_error_settings INTERFACE)
add_library(nw::error_settings ALIAS nw_error_settings)

add_library(nw_defaults_features INTERFACE)
add_library(nw::defaults_features ALIAS nw_defaults_features)

add_library(nw_optimize_settings INTERFACE)
add_library(nw::optimize_settings ALIAS nw_optimize_settings)

target_compile_options(
        nw_error_settings
        INTERFACE
        -Wall
        -Wextra # reasonable and standard
        -Wfatal-errors # short error report
        -Wshadow # warn the user if a variable declaration shadows one from a
        -Wshorten-64-to-32
        # parent context
        -Wnon-virtual-dtor # warn the user if a class with virtual functions has a
        # non-virtual destructor. This helps catch hard to track down memory errors
        -Wcast-align     # warn for potential performance problem casts
        #-Wunused         # warn on anything being unused
        -Woverloaded-virtual # warn if you overload (not override) a virtual
        # function
        -Wnull-dereference # warn if a null dereference is detected
        -Wdouble-promotion # warn if float is implicit promoted to double
        -Wformat=2 # warn on security issues around functions that format output
)

if (NW_WARNINGS_AS_ERRORS)
    target_compile_options(
            tw_error_settings
            INTERFACE
            -Werror
    )
endif ()

target_compile_features(nw_defaults_features INTERFACE cxx_std_20)

target_compile_options(nw_optimize_settings INTERFACE
        $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:Clang>>:-O0 -g>
        $<$<AND:$<CONFIG:Debug>,$<CXX_COMPILER_ID:AppleClang>>:-O0 -g>
        $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:Clang>>:-O2>
        $<$<AND:$<CONFIG:Release>,$<CXX_COMPILER_ID:AppleClang>>:-O2>
        )

function(set_project_warnings project_name)
    target_link_libraries(${project_name} INTERFACE nw::error_settings nw::defaults_features nw::optimize_settings)

    if (NOT TARGET ${project_name})
        message(AUTHOR_WARNING "${project_name} is not a target, thus no compiler warning were added.")
    endif ()
endfunction()
