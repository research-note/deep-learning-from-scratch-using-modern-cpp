/*
 * Build softmax lib.
 *
 * Copyright Paran Lee
 *
 */

#include "lib/softmax.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <cmath> 

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
    auto max = *max_element(x.begin(), x.end());
    std::for_each(x.begin(), x.end(), [](auto v) {
        std::cout << v << ' ';
    });

    T y = std::transform(x.begin(), x.end(), x.begin(), [max](auto v) -> auto { return exp(v - max); });

    auto sum = std::accumulate(y.begin(), y.end(), decltype(y)::value_type(0));
    return std::transform(y.begin(), y.end(), y.begin(), [max](auto v) -> auto { return v / sum; });
}
