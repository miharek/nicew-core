//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_ENUM(uint32_t)
enum NWAESPaddingMode {
    NWAESPaddingModeZero = 0,   // padding value is zero
    NWAESPaddingModePKCS7 = 1,  // padding value is the number of padding bytes; for even size add an extra block
};

NW_EXTERN_C_END
