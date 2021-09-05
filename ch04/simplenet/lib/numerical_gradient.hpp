/*
 * Build numerical gradient lib.
 *
 * Copyright Paran Lee
 *
 */

#ifndef CH04_LIB_SIMPLENET_NUMERICAL_GRADIENT_HPP_
#define CH04_LIB_SIMPLENET_NUMERICAL_GRADIENT_HPP_

template <typename F, typename T>
T numerical_gradient(F f, T x);

#include "numerical_gradient.cc"

#endif  // CH04_LIB_SIMPLENET_NUMERICAL_GRADIENT_HPP_
