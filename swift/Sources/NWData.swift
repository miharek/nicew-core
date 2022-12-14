// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

/// Converts a Data struct to NWData/UnsafeRawPointer caller must delete it after use.
public func NWDataCreateWithNSData(_ data: Data) -> UnsafeRawPointer {
    return NWDataCreateWithBytes([UInt8](data), data.count)
}

/// Converts a NWData/UnsafeRawPointer (will be deleted within this call) to a Data struct.
public func NWDataNSData(_ data: UnsafeRawPointer) -> Data {
    defer {
        NWDataDelete(data)
    }
    return Data(bytes: NWDataBytes(data), count: NWDataSize(data))
}
