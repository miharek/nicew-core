//
// Created by Mihael Rek on 02/08/2022.
//

#pragma once

namespace NW::operators::details {

    template <typename T>
    class empty_base {};

} // namespace NW::operators::details

namespace NW {

    template <class T, class B = operators::details::empty_base<T>>
    struct equality_comparable : B {
        friend bool operator!=(const T& x, const T& y) { return !(x == y); }
    };

} // namespace NW
