//
// Created by Mihael Rek on 02/08/2022.
//

#include "OutPoint.h"

#include "../BinaryCoding.h"

using namespace NW::Bitcoin;

void OutPoint::encode(Data& data) const noexcept {
    std::copy(std::begin(hash), std::end(hash), std::back_inserter(data));
    encode32LE(index, data);
    // sequence is encoded in TransactionInputs
}
