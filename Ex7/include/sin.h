#pragma once

#include "factorial.h"
#include "faster_pow.h"

namespace Ex7
{
template <int N>
double sin(double x)
{
    return sin<N - 1>(x) + (N % 2 ? 1 : -1) * fastPow<(2 * N - 1)>(x) / factorial<2 * N - 1>::val;
}

template <>
double sin<0>(double x)
{
    return 0;
}
}  // namespace Ex7
