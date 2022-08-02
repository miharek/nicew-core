//
// Created by Mihael Rek on 02/08/2022.
//

#include "TransactionInput.h"

#include "../BinaryCoding.h"

using namespace NW::Bitcoin;

void TransactionInput::encode(Data& data) const {
    auto& outpoint = reinterpret_cast<const NW::Bitcoin::OutPoint&>(previousOutput);
    outpoint.encode(data);
    script.encode(data);
    encode32LE(sequence, data);
}

void TransactionInput::encodeWitness(Data& data) const {
    encodeVarInt(scripNWitness.size(), data);
    for (auto& item : scripNWitness) {
        encodeVarInt(item.size(), data);
        std::copy(std::begin(item), std::end(item), std::back_inserter(data));
    }
}
