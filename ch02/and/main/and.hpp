/*
 * Build obj linking with cc_library file example.
 *
 * Copyright Bazel organization
 *
 */

#ifndef CPP_TUTORIAL_STAGE3_MAIN_HELLO_GREET_H_
#define CPP_TUTORIAL_STAGE3_MAIN_HELLO_GREET_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T>
T And(const T& x1, const T& x2, const T& b);

/* template <typename T>
T And(const T& x1, const T& x2, const T& b) {
    vector<T> v{ x1, x2 };
    vector<T> w { 0.5, 0.5 };

    T res = std::inner_product(v.begin(), v.end(), w.begin(), 0) + b;
    std::cout << "Inner product of inputs and weights: " << res << '\n';

    return res > 0 ? 1 : 0;
} */

#include "and.cc"

#endif  // CPP_TUTORIAL_STAGE3_MAIN_HELLO_GREET_H_
