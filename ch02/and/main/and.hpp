/*
 * Build obj linking with cc_library file example.
 *
 * Copyright Bazel organization
 *
 */

#ifndef CH02_AND_H_
#define CH02_AND_H_

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

template <typename T>
T And(const T& x1, const T& x2, const T& b);

#include "and.cc"

#endif  // CH02_AND_H_
