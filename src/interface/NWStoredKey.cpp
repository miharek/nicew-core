//
// Created by Mihael Rek on 02/08/2022.
//

#include <NiceWCore/NWStoredKey.h>

#include "../Coin.h"
#include "../Data.h"
#include "../HDWallet.h"
#include "../Keystore/StoredKey.h"

#include <stdexcept>
#include <cassert>

using namespace NW::Keystore;

struct NWStoredKey* _Nullable NWStoredKeyLoad(NWString* _Nonnull path) {
try {
const auto& pathString = *reinterpret_cast<const std::string*>(path);
return new NWStoredKey{ StoredKey::load(pathString) };
} catch (...) {
return nullptr;
}
}

struct NWStoredKey* _Nonnull NWStoredKeyCreateLevel(NWString* _Nonnull name, NWData* _Nonnull password, enum NWStoredKeyEncryptionLevel encryptionLevel) {
const auto& nameString = *reinterpret_cast<const std::string*>(name);
const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
return new NWStoredKey{ StoredKey::createWithMnemonicRandom(nameString, passwordData, encryptionLevel) };
}

struct NWStoredKey* _Nonnull NWStoredKeyCreate(NWString* _Nonnull name, NWData* _Nonnull password) {
return NWStoredKeyCreateLevel(name, password, NWStoredKeyEncryptionLevelDefault);
}

struct NWStoredKey* _Nullable NWStoredKeyImportPrivateKey(NWData* _Nonnull privateKey, NWString* _Nonnull name, NWData* _Nonnull password, enum NWCoinType coin) {
try {
const auto& privateKeyData = *reinterpret_cast<const NW::Data*>(privateKey);
const auto& nameString = *reinterpret_cast<const std::string*>(name);
const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
return new NWStoredKey{ StoredKey::createWithPrivateKeyAddDefaultAddress(nameString, passwordData, coin, privateKeyData) };
} catch (...) {
return nullptr;
}
}

struct NWStoredKey* _Nullable NWStoredKeyImportHDWallet(NWString* _Nonnull mnemonic, NWString* _Nonnull name, NWData* _Nonnull password, enum NWCoinType coin) {
try {
const auto& mnemonicString = *reinterpret_cast<const std::string*>(mnemonic);
const auto& nameString = *reinterpret_cast<const std::string*>(name);
const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
return new NWStoredKey{ StoredKey::createWithMnemonicAddDefaultAddress(nameString, passwordData, mnemonicString, coin) };
} catch (...) {
return nullptr;
}
}

struct NWStoredKey* _Nullable NWStoredKeyImportJSON(NWData* _Nonnull json) {
try {
const auto& d = *reinterpret_cast<const NW::Data*>(json);
const auto parsed = nlohmann::json::parse(d);
return new NWStoredKey{ StoredKey::createWithJson(nlohmann::json::parse(d)) };
} catch (...) {
return nullptr;
}
}

void NWStoredKeyDelete(struct NWStoredKey* _Nonnull key) {
    delete key;
}

NWString* _Nullable NWStoredKeyIdentifier(struct NWStoredKey* _Nonnull key) {
    if (!key->impl.id) {
        return nullptr;
    }
    return NWStringCreateWithUTF8Bytes(key->impl.id->c_str());
}

NWString* _Nonnull NWStoredKeyName(struct NWStoredKey* _Nonnull key) {
    return NWStringCreateWithUTF8Bytes(key->impl.name.c_str());
}

bool NWStoredKeyIsMnemonic(struct NWStoredKey* _Nonnull key) {
    return key->impl.type == StoredKeyType::mnemonicPhrase;
}

size_t NWStoredKeyAccountCount(struct NWStoredKey* _Nonnull key) {
    return key->impl.accounts.size();
}

struct NWAccount* _Nullable NWStoredKeyAccount(struct NWStoredKey* _Nonnull key, size_t index) {
    if (index >= key->impl.accounts.size()) {
        return nullptr;
    }

    return new NWAccount{ key->impl.accounts[index] };
}

struct NWAccount* _Nullable NWStoredKeyAccountForCoin(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, struct NWHDWallet* _Nullable wallet) {
    try {
        const auto account = key->impl.account(coin, (wallet ? &wallet->impl : nullptr));
        // Note: std::optional.value() is not available in XCode with target < iOS 12, using *
        return (!account.has_value()) ? nullptr : new NWAccount{ *account };
    } catch (...) {
        return nullptr;
    }
}

struct NWAccount* _Nullable NWStoredKeyAccountForCoinDerivation(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, NWDerivation derivation, struct NWHDWallet* _Nullable wallet) {
    try {
        if (wallet == nullptr) {
            return nullptr;
        }
        const auto account = key->impl.account(coin, derivation, wallet->impl);
        return new NWAccount{ account };
    } catch (...) {
        return nullptr;
    }
}

void NWStoredKeyRemoveAccountForCoin(struct NWStoredKey* _Nonnull key, enum NWCoinType coin) {
    key->impl.removeAccount(coin);
}

void NWStoredKeyRemoveAccountForCoinDerivation(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, enum NWDerivation derivation) {
    key->impl.removeAccount(coin, derivation);
}

void NWStoredKeyRemoveAccountForCoinDerivationPath(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, NWString* _Nonnull derivationPath) {
    const auto dp = NW::DerivationPath(*reinterpret_cast<const std::string*>(derivationPath));
    key->impl.removeAccount(coin, dp);
}

void NWStoredKeyAddAccountDerivation(struct NWStoredKey* _Nonnull key, NWString* _Nonnull address, enum NWCoinType coin, enum NWDerivation derivation, NWString* _Nonnull derivationPath, NWString* _Nonnull publicKey, NWString* _Nonnull extendedPublicKey) {
    const auto& addressString = *reinterpret_cast<const std::string*>(address);
    const auto& publicKeyString = *reinterpret_cast<const std::string*>(publicKey);
    const auto& extendedPublicKeyString = *reinterpret_cast<const std::string*>(extendedPublicKey);
    const auto dp = NW::DerivationPath(*reinterpret_cast<const std::string*>(derivationPath));
    key->impl.addAccount(addressString, coin, derivation, dp, publicKeyString, extendedPublicKeyString);
}

void NWStoredKeyAddAccount(struct NWStoredKey* _Nonnull key, NWString* _Nonnull address, enum NWCoinType coin, NWString* _Nonnull derivationPath, NWString* _Nonnull publicKey, NWString* _Nonnull extendedPublicKey) {
    return NWStoredKeyAddAccountDerivation(key, address, coin, NWDerivationDefault, derivationPath, publicKey, extendedPublicKey);
}

bool NWStoredKeyStore(struct NWStoredKey* _Nonnull key, NWString* _Nonnull path) {
    try {
        const auto& pathString = *reinterpret_cast<const std::string*>(path);
        key->impl.store(pathString);
        return true;
    } catch (...) {
        return false;
    }
}

NWData* _Nullable NWStoredKeyDecryptPrivateKey(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password) {
    try {
        const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
        const auto data = key->impl.payload.decrypt(passwordData);
        return NWDataCreateWithBytes(data.data(), data.size());
    } catch (...) {
        return nullptr;
    }
}

NWString* _Nullable NWStoredKeyDecryptMnemonic(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password) {
    try {
        const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
        const auto data = key->impl.payload.decrypt(passwordData);
        const auto string = std::string(data.begin(), data.end());
        return NWStringCreateWithUTF8Bytes(string.c_str());
    } catch (...) {
        return nullptr;
    }
}

struct NWPrivateKey* _Nullable NWStoredKeyPrivateKey(struct NWStoredKey* _Nonnull key, enum NWCoinType coin, NWData* _Nonnull password) {
    try {
        const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
        return new NWPrivateKey{ key->impl.privateKey(coin, passwordData) };
    } catch (...) {
        return nullptr;
    }
}

struct NWHDWallet* _Nullable NWStoredKeyWallet(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password) {
    try {
        const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
        return new NWHDWallet{ key->impl.wallet(passwordData) };
    } catch (...) {
        return nullptr;
    }
}

NWData* _Nullable NWStoredKeyExportJSON(struct NWStoredKey* _Nonnull key) {
    const auto json = key->impl.json().dump();
    return NWDataCreateWithBytes(reinterpret_cast<const uint8_t*>(json.data()), json.size());
}

bool NWStoredKeyFixAddresses(struct NWStoredKey* _Nonnull key, NWData* _Nonnull password) {
    try {
        const auto passwordData = NW::data(NWDataBytes(password), NWDataSize(password));
        key->impl.fixAddresses(passwordData);
        return true;
    } catch (...) {
        return false;
    }
}

NWString* _Nullable NWStoredKeyEncryptionParameters(struct NWStoredKey* _Nonnull key) {
    if (!key->impl.id) {
        return nullptr;
    }
    const std::string params = key->impl.payload.json().dump();
    return NWStringCreateWithUTF8Bytes(params.c_str());
}
