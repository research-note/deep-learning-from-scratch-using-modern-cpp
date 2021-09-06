/*
 * Build softmax lib.
 *
 * Copyright Paran Lee
 *
 */

#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath>

#include "lib/softmax.hpp"

// def softmax(x):
//     if x.ndim == 2:
//         x = x.T
//         x = x - np.max(x, axis=0)
//         y = np.exp(x) / np.sum(np.exp(x), axis=0)
//         return y.T 

//     x = x - np.max(x) # 오버플로 대책
//     return np.exp(x) / np.sum(np.exp(x))


template <typename T>
T softmax(T x) {
    auto max = std::max_element(x.begin(), x.end());

    std::transform(std::execution::par, x.begin(), x.end(),
        x.begin(), [max](auto v) -> auto {
            return exp(v - max);
        });

    const auto sum = std::reduce(std::execution::par,
        x.cbegin(), x.cend());

    std::transform(std::execution::par, x.begin(), x.end(),
        x.begin(), [sum](auto v) -> auto {
            return v / sum;
        });

    std::cout << "softmax(x) :" << std::endl;
    std::for_each(x.begin(), x.end(),
        [](auto v) { std::cout << v << ' '; });
    std::cout << std::endl;

    return x;
}
