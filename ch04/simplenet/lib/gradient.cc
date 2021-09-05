/*
 * Build gradient lib.
 *
 * Copyright Paran Lee
 *
 */

#include <iostream>

#include "lib/gradient.hpp"

template <typename F, typename T>
T gradient(F f, T x) {
    const auto h = 1e-4;
    const auto hh = 2 * h;
    std::transform(x.begin(), x.end(), x.begin(),
        [f, h, hh](auto v) -> auto {
            return ( f(v + h) - f(v - h) ) / hh;
        });

    return x;
}
