#pragma once

#include <cstdio>

namespace Ex7
{
template <size_t N>
struct factorial
{
    enum
    {
        val = (N * factorial<N - 1>::val)
    };
};

template <>
struct factorial<0>
{
    enum
    {
        val = 1
    };
};
}  // namespace Ex7
