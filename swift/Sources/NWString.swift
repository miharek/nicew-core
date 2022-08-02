// Copyright © 2017-2020 Trust Wallet.
//
// This file is part of Trust. The full Trust copyright notice, including
// terms governing use, modification, and redistribution, is contained in the
// file LICENSE at the root of the source code distribution tree.

import Foundation

/// Converts a String struct to NWString/UnsafeRawPointer, caller must delete it after use.
public func NWStringCreateWithNSString(_ string: String) -> UnsafeRawPointer {
    return NWStringCreateWithUTF8Bytes([CChar](string.utf8CString))
}

/// Converts a NWString/UnsafeRawPointer (will be deleted within this call) to a String struct.
public func NWStringNSString(_ string: UnsafeRawPointer) -> String {
    defer {
        NWStringDelete(string)
    }
    return String(utf8String: NWStringUTF8Bytes(string))!
}
