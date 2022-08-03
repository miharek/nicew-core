//
// Created by Mihael Rek on 02/08/2022.
//

#include "Entry.h"

#include "Address.h"
#include "SegwitAddress.h"
#include "Signer.h"

#include <TrezorCrypto/cash_addr.h>

using namespace NW::Bitcoin;
using namespace NW;
using namespace std;

bool Entry::validateAddress(NWCoinType coin, const string& address, byte p2pkh, byte p2sh,
                            const char* hrp) const {
    switch (coin) {
    case NWCoinTypeBitcoin:
        return SegwitAddress::isValid(address, hrp) || Address::isValid(address, {{p2pkh}, {p2sh}});
    default:
        return Address::isValid(address, {{p2pkh}, {p2sh}});
    }
}

string Entry::normalizeAddress(NWCoinType coin, const string& address) const {
    switch (coin) {
    default:
        // no change
        return address;
    }
}

string Entry::deriveAddress(NWCoinType coin, NWDerivation derivation, const PublicKey& publicKey,
                            byte p2pkh, const char* hrp) const {
    switch (coin) {
    case NWCoinTypeBitcoin:
        switch (derivation) {
        case NWDerivationBitcoinLegacy:
            return Address(publicKey, p2pkh).string();
        case NWDerivationBitcoinSegwit:
        case NWDerivationDefault:
        default:
            return SegwitAddress(publicKey, hrp).string();
        }
    default:
        return Address(publicKey, p2pkh).string();
    }
}

template<typename CashAddress>
inline Data cashAddressToData(const CashAddress&& addr) {
    return subData(addr.getData(), 1);
}

Data Entry::addressToData(NWCoinType coin, const std::string& address) const {
    switch (coin) {
        case NWCoinTypeBitcoin:
            {
                const auto decoded = SegwitAddress::decode(address);
                if (!std::get<2>(decoded)) {
                    return Data();
                }
                return std::get<0>(decoded).witnessProgram;
            }
        default:
            return Data();
    }
}

void Entry::sign([[maybe_unused]] NWCoinType coin, const Data& dataIn, Data& dataOut) const {
    signTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

void Entry::plan([[maybe_unused]] NWCoinType coin, const Data& dataIn, Data& dataOut) const {
    planTemplate<Signer, Proto::SigningInput>(dataIn, dataOut);
}

Data Entry::preImageHashes([[maybe_unused]] NWCoinType coin, const Data& txInputData) const {
    return txCompilerTemplate<Proto::SigningInput, Proto::PreSigningOutput>(
        txInputData, [](auto&& input, auto&& output) { output = Signer::preImageHashes(input); });
}

void Entry::compile([[maybe_unused]] NWCoinType coin, const Data& txInputData, const std::vector<Data>& signatures, const std::vector<PublicKey>& publicKeys, Data& dataOut) const {
    auto txCompilerFunctor = [&signatures, &publicKeys](auto&& input, auto&& output) noexcept {
        if (signatures.empty() || publicKeys.empty()) {
            output.set_error(Common::Proto::Error_invalid_params);
            output.set_error_message("empty signatures or publickeys");
            return;
        }

        if (signatures.size() != publicKeys.size()) {
            output.set_error(Common::Proto::Error_invalid_params);
            output.set_error_message("signatures size and publickeys size not equal");
            return;
        }

        HashPubkeyList externalSignatures;
        auto insertFunctor = [](auto&& signature, auto&& pubkey) noexcept {
            return std::make_pair(signature, pubkey.bytes);
        };
        transform(begin(signatures), end(signatures), begin(publicKeys),
                  back_inserter(externalSignatures), insertFunctor);
        output = Signer::sign(input, externalSignatures);
    };

    dataOut = txCompilerTemplate<Proto::SigningInput, Proto::SigningOutput>(txInputData,
                                                                            txCompilerFunctor);
}
