//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWHDVersion.h>

#pragma clang diagnostic push
#pragma clang diagnostic fatal "-Wswitch"

bool NWHDVersionIsPublic(enum NWHDVersion version) {
    switch (version) {
        case NWHDVersionXPUB:
        case NWHDVersionYPUB:
        case NWHDVersionZPUB:
            return true;

        case NWHDVersionNone:
        default:
            return false;
    }
}

bool NWHDVersionIsPrivate(enum NWHDVersion version) {
    switch (version) {
        case NWHDVersionXPRV:
        case NWHDVersionYPRV:
        case NWHDVersionZPRV:
            return true;

        case NWHDVersionNone:
        default:
            return false;
    }
}

#pragma clang diagnostic pop
