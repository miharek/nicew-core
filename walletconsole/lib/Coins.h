// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include <string>
#include <vector>
#include <map>
#include <sstream>

namespace NW::WalletConsole {

using namespace std;

class Coin {
public:
    int c;
    string id;
    string name;
    string symbol;
    int curve; // NWCurve
    int pubKeyType; // NWPublicKeyType
    string derivPath;
};

class Coins {
public:
    Coins(ostream& out) : _out(out) {}
    void coins() const;
    bool findCoin(const string& coin, Coin& coin_out) const;
    void init();
protected:
    void scanCoins();
    int findCoinId(const string& coin) const;
    static int pubKeyTypeFromCurve(int cc);
    ostream& _out;
    map<int, Coin> _coinsByNum;
    map<string, Coin> _coinsById;
    map<string, Coin> _coinsByName;
    map<string, Coin> _coinsBySymbol;
};

} // namespace NW::WalletConsole
