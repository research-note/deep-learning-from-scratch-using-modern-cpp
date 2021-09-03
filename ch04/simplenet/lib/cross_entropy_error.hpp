/*
 * Build cross_entropy_error lib.
 *
 * Copyright Paran Lee
 *
 */

#ifndef CH04_SIMPLENET_LIB_ENTROPY_ERROR_H_
#define CH04_SIMPLENET_LIB_ENTROPY_ERROR_H_

template <typename Y, typename T>
Y cross_entropy_error(Y y, T t);

#include "cross_entropy_error.cc"

#endif  // CH04_SIMPLENET_LIB_ENTROPY_ERROR_H_
