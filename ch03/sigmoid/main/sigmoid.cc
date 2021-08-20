/*
 * 
 * Copyright Paran Lee
 *
 */

#include <cmath>

using namespace std;

template <typename T>
T And(const T& x) {
    return 1 / (1 + exp(x));
}
