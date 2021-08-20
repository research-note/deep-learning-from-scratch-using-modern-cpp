/*
 * 
 * Copyright Paran Lee
 *
 */

#include <cmath>

using namespace std;

template <typename T>
T sigmoid(const T& x) {
    return 1 / (1 + exp(-x));
}
