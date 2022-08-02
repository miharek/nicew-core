//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

#include <cstddef>

#include <type_traits>

#include <TrezorCrypto/memzero.h>

namespace NW {

    template <typename T>
    static inline void memzero(T* data, std::size_t len = sizeof(T)) noexcept {
    static_assert(std::is_trivial_v<T>, "type should be a pod");
    ::memzero(data, len);
}

} // namespace NW