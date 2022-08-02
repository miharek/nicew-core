//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWBitcoinSigHashType.h>
#include "../Bitcoin/SigHashType.h"

bool NWBitcoinSigHashTypeIsSingle(enum NWBitcoinSigHashType type) {
    return NW::Bitcoin::hashTypeIsSingle(type);
}

bool NWBitcoinSigHashTypeIsNone(enum NWBitcoinSigHashType type) {
    return NW::Bitcoin::hashTypeIsNone(type);
}
