
// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#include "Coins.h"

#include "WalletConsole.h"
#include "Util.h"

#include <NiceWCore/NWCoinTypeConfiguration.h>
#include <NiceWCore/NWPublicKeyType.h>
#include "Data.h"
#include "Coin.h"

#include <iostream>
#include <vector>
#include <cassert>

#define WRAPS(x) std::shared_ptr<NWString>(x, NWStringDelete)

namespace NW::WalletConsole {

using namespace std;

void Coins::coins() const {
    for (auto c: _coinsById) {
        _out << c.second.symbol << " \t " << c.second.id << " \t '" << c.second.name << "'" << endl;
    }
    _out << _coinsById.size() << " coins listed." << endl;
}

int Coins::findCoinId(const string& coin) const {
    if (_coinsById.find(coin) != _coinsById.end()) {
        // Note: simple map[key] does not work for const...
        return _coinsById.find(coin)->second.c;
    }
    if (_coinsByName.find(coin) != _coinsByName.end()) {
        return _coinsByName.find(coin)->second.c;
    }
    if (_coinsBySymbol.find(coin) != _coinsBySymbol.end()) {
        return _coinsBySymbol.find(coin)->second.c;
    }
    // not found
    return -1;
}

bool Coins::findCoin(const string& coin, Coin& coin_out) const {
    int c = findCoinId(coin);
    if (c < 0) {
        _out << "Error: No such coin '" << coin << "'" << endl;
        return false;
    }
    coin_out = _coinsByNum.find(c)->second;
    return true;
}

void Coins::init() {
    // not very nice method: try each ID number, and record the ones that are valid coins
    _out << "Loading coins ... ";
    scanCoins();
    _out << _coinsById.size() << " coins loaded." << endl;
}

void Coins::scanCoins() {
    const auto coins = NW::getCoinTypes();
    for (auto c: coins) {
        auto symbolNW = WRAPS(NWCoinTypeConfigurationGetSymbol(c));
        assert(NWStringSize(symbolNW.get()) != 0);
        string id = NWStringUTF8Bytes(WRAPS(NWCoinTypeConfigurationGetID(c)).get());
        Util::toLower(id);
        string symbol = NWStringUTF8Bytes(symbolNW.get());
        Util::toLower(symbol);
        string name = NWStringUTF8Bytes(WRAPS(NWCoinTypeConfigurationGetName(c)).get());
        Util::toLower(name);
        int curve = (int)NWCoinTypeCurve(c);
        int pubKeyType = (int)NW::publicKeyType(c);
        string derivPath = NW::derivationPath(c).string();
        Coin coin = Coin{c, id, name, symbol, curve, pubKeyType, derivPath};
        _coinsByNum[c] = coin;
        _coinsById[id] = coin;
        _coinsByName[name] = coin;
        _coinsBySymbol[symbol] = coin;
    }
}

} // namespace NW::WalletConsole
