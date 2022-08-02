// Copyright © 2017-2022 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

#pragma once

#include "Data.h"
#include "PublicKey.h"

#include <NiceWCore/NWPrivateKeyType.h>
#include <NiceWCore/NWCurve.h>

namespace NW {

class PrivateKey {
  public:
    /// The number of bytes in a private key.
    static const size_t _size = 32;
    /// The number of bytes in a Cardano key (NWo extended ed25519 keys + chain code)
    static const size_t cardanoKeySize = 2 * 3 * 32;

    /// The private key bytes:
    /// - common case: 'size' bytes
    /// - double extended case: 'cardanoKeySize' bytes, key+extension+chainCode+second+secondExtension+secondChainCode
    Data bytes;

    /// Optional members for extended keys and second extended keys
    Data key() const { return subData(bytes, 0, 32); }
    Data extension() const { return subData(bytes, 32, 32); }
    Data chainCode() const { return subData(bytes, 2*32, 32); }
    Data secondKey() const { return subData(bytes, 3*32, 32); }
    Data secondExtension() const { return subData(bytes, 4*32, 32); }
    Data secondChainCode() const { return subData(bytes, 5*32, 32); }

    /// Determines if a collection of bytes makes a valid private key.
    static bool isValid(const Data& data);

    /// Determines if a collection of bytes and curve make a valid private key.
    static bool isValid(const Data& data, NWCurve curve);

    // obtain private key type used by the curve/coin
    static NWPrivateKeyType getType(NWCurve curve) noexcept;

    /// Initializes a private key with an array of bytes.  Size must be exact (normally 32, or 192 for extended)
    explicit PrivateKey(const Data& data);

    /// Initializes a private key from a string of bytes.
    explicit PrivateKey(const std::string& data) : PrivateKey(NW::data(data)) {}

    /// Initializes a Cardano style key
    explicit PrivateKey(
        const Data& bytes1, const Data& extension1, const Data& chainCode1,
        const Data& bytes2, const Data& extension2, const Data& chainCode2);

    PrivateKey(const PrivateKey& other) = default;
    PrivateKey& operator=(const PrivateKey& other) = default;

    PrivateKey(PrivateKey&& other) = default;
    PrivateKey& operator=(PrivateKey&& other) = default;

    virtual ~PrivateKey() { cleanup(); }

    /// Returns the public key for this private key.
    PublicKey getPublicKey(enum NWPublicKeyType type) const;

    /// Computes an EC Diffie-Hellman secret in constant time
    /// Supported curves: secp256k1
    Data getSharedKey(const PublicKey& publicKey, NWCurve curve) const;

    /// Signs a digest using the given ECDSA curve.
    Data sign(const Data& digest, NWCurve curve) const;

    /// Signs a digest using the given ECDSA curve and prepends the recovery id (a la graphene)
    /// Only a sig that passes canonicalChecker is returned
    Data sign(const Data& digest, NWCurve curve, int(*canonicalChecker)(uint8_t by, uint8_t sig[64])) const;

    /// Signs a digest using the given ECDSA curve. The result is encoded with
    /// DER.
    Data signAsDER(const Data& digest) const;

    /// Signs a digest using given ECDSA curve, returns Zilliqa schnorr signature
    Data signZilliqa(const Data& message) const;

    /// Cleanup contents (fill with 0s), called before destruction
    void cleanup();
};

inline bool operator==(const PrivateKey& lhs, const PrivateKey& rhs) {
    return lhs.bytes == rhs.bytes;
}
inline bool operator!=(const PrivateKey& lhs, const PrivateKey& rhs) {
    return lhs.bytes != rhs.bytes;
}

} // namespace NW

/// Wrapper for C interface.
struct NWPrivateKey {
    NW::PrivateKey impl;
};
