/*
 * Build gradient lib.
 *
 * Copyright Paran Lee
 *
 */

#include "lib/gradient.hpp"
#include <iostream>

// def numerical_gradient(f, x):
//     h = 1e-4 # 0.0001
//     grad = np.zeros_like(x)

//     it = np.nditer(x, flags=['multi_index'], op_flags=['readwrite'])
//     while not it.finished:
//         idx = it.multi_index
//         tmp_val = x[idx]
//         x[idx] = float(tmp_val) + h
//         fxh1 = f(x) # f(x+h)

//         x[idx] = tmp_val - h 
//         fxh2 = f(x) # f(x-h)
//         grad[idx] = (fxh1 - fxh2) / (2*h)

//         x[idx] = tmp_val # 값 복원
//         it.iternext()   

//     return grad

template <typename F, typename T>
T gradient(F f, T x) {
    const auto h = 1e-4;
    const auto hh = 2 * h;
    T grad = std::transform(x.begin(), x.end(), x.begin(), [f, h, hh](auto v) -> auto {
        return ( f(v + h) - f(v - h) ) / hh;
    });

    return grad;
}
