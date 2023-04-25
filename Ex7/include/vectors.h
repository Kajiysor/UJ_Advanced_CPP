#pragma once

#include <cstddef>

namespace Ex7
{
template <size_t N>
double inner(double *x, double *y)
{
    return (*x) * (*y) + inner<N - 1>(x + 1, y + 1);
}

template <>
double inner<1>(double *x, double *y)
{
    return (*x) * (*y);
}

template <std::size_t N, typename T = double>
struct Inner
{
    static T dot(T const *x, T const *y) { return (*x) * (*y) + Inner<N - 1, T>::dot(x + 1, y + 1); }
};

template <typename T>
struct Inner<1, T>
{
    static T dot(T const *x, T const *y) { return (*x) * (*y); }
};

template <std::size_t N, typename T = double>
T dot(T const *x, T const *y)
{
    return Inner<N, T>::dot(x, y);
}
}  // namespace Ex7
