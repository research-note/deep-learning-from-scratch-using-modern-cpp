/*
 * Build cross_entropy_error lib.
 *
 * Copyright Paran Lee
 *
 */

#include <vector>
#include <functional>
#include <iostream>
#include <numeric>
#include <execution>

#include <cmath>

#include "lib/cross_entropy_error.hpp"

template <typename Y, typename T>
auto cross_entropy_error(Y y, T t) {
    const auto delta = 1e-7;
    std::transform(std::execution::par,
        y.begin(), y.end(), t.begin(), y.begin(),
        [&delta](auto yv, auto tv) {
            return -log(yv + delta) * tv; 
        });
    std::cout << "cross_entropy_error(y, t) :" << std::endl;
    for (auto yv : y) {
        std::cout << ' ' << yv;
    }
    std::cout << std::endl;
    const auto result = std::reduce(std::execution::par, y.cbegin(), y.cend());
    std::cout << "cross_entropy_error(y, t) :" << result << std::endl;
    return result;
}
