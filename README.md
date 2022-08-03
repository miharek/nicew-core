# nicew-core

## Prerequisites on macOS
- CMake "brew install cmake"
- Boost "brew install boost"
- Xcode
- Xcode command line tools: "xcode-select --install"
- Other tools: "brew install git ninja autoconf automake libtool xcodegen clang-format ccache cocoapods
- Android Studio
- Android NDK

## Full build
- "./bootstrap.sh"
or, smaller steps:
- "./tools/install-dependencies

- "cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Debug"
  "make -Cbuild"
