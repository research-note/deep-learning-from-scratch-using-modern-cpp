/*
 * Build numerical gradient lib.
 *
 * Copyright Paran Lee
 *
 */

#include <iostream>

#include "lib/numerical_gradient.hpp"

template <typename F, typename T>
T numerical_gradient(F f, T x) {
    const auto h = 1e-4;
    const auto hh = 2 * h;

    std::transform(x.begin(), x.end(), x.begin(),
        [f, h, hh](auto v) -> auto {
            return ( f(v + h) - f(v - h) ) / hh;
        });

    std::cout << "numerical_gradient(y, t) :" << std::endl;
    for (auto xv : x) {
        std::cout << ' ' << xv;
    }
    std::cout << std::endl;

    return x;
}
