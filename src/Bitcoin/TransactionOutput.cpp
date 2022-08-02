//
// Created by Mihael Rek on 02/08/2022.
//

#include "TransactionOutput.h"

#include "../BinaryCoding.h"

using namespace TW::Bitcoin;

void TransactionOutput::encode(Data& data) const {
    encode64LE(value, data);
    script.encode(data);
}
