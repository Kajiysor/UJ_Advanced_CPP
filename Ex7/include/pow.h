#pragma once

#include <cstdio>

namespace Ex7
{
template <size_t N, size_t M>
struct pow
{
    enum
    {
        val = N * pow<N, M - 1>::val
    };
};

template <size_t N>
struct pow<N, 0>
{
    enum
    {
        val = 1
    };
};

template <size_t M>
struct pow<0, M>
{
    enum
    {
        val = 0
    };
};

template <size_t M>
struct pow<1, M>
{
    enum
    {
        val = 1
    };
};

template <>
struct pow<0, 0>
{
    enum
    {
        val = 0
    };
};
}  // namespace Ex7
