#pragma once

#include <cstdio>

namespace Ex7
{
template <size_t N>
double fastPow(double x)
{
    return ((N % 2) ? x : 1) * fastPow<N / 2>(x * x);
}

template <>
double fastPow<1>(double x)
{
    return x;
};

template <>
double fastPow<0>(double x)
{
    return 1.0;
};
}  // namespace Ex7
