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
        case NWHDVersionLTUB:
        case NWHDVersionMTUB:
        case NWHDVersionDPUB:
        case NWHDVersionDGUB:
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
        case NWHDVersionLTPV:
        case NWHDVersionMTPV:
        case NWHDVersionDPRV:
        case NWHDVersionDGPV:
            return true;

        case NWHDVersionNone:
        default:
            return false;
    }
}

#pragma clang diagnostic pop
