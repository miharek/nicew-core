//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include "NWBase.h"

NW_EXTERN_C_BEGIN

NW_EXPORT_ENUM(uint32_t)
enum NWBitcoinSigHashType {
    NWBitcoinSigHashTypeAll = 0x01,
    NWBitcoinSigHashTypeNone = 0x02,
    NWBitcoinSigHashTypeSingle = 0x03,
    NWBitcoinSigHashTypeFork = 0x40,
    NWBitcoinSigHashTypeForkBTG = 0x4f40,
    NWBitcoinSigHashTypeAnyoneCanPay = 0x80
};

NW_EXPORT_METHOD
bool NWBitcoinSigHashTypeIsSingle(enum NWBitcoinSigHashType type);

NW_EXPORT_METHOD
bool NWBitcoinSigHashTypeIsNone(enum NWBitcoinSigHashType type);

NW_EXTERN_C_END
