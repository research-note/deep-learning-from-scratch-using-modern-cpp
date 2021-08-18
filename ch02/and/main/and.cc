/*
 * 
 * Copyright Paran Lee
 *
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T>
T And(const T& x1, const T& x2, const T& b) {
    vector<T> v{ x1, x2 };
    vector<T> w { 0.5, 0.5 };
    
    T res = std::inner_product(v.begin(), v.end(), w.begin(), b);
    std::cout << "Inner product of inputs and weights: " << res << '\n';

    return res > 0 ? 1 : 0;
}
