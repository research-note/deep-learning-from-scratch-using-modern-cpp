/*
 * Build gradient lib.
 *
 * Copyright Paran Lee
 *
 */

#ifndef CH04_LIB_SIMPLENET_GRADIENT_HPP_
#define CH04_LIB_SIMPLENET_GRADIENT_HPP_

template <typename F, typename T>
T gradient(F f, T x);

#include "gradient.cc"

#endif  // CH04_LIB_SIMPLENET_GRADIENT_HPP_
