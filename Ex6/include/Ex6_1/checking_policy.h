#ifndef _checking_policy_
#define _checking_policy_

#include <cstdio>
#include <iostream>

#include "color.h"

namespace Ex6
{
template <int R = 0, int G = 0, int B = 0>
struct Default_on_error_policy
{
    static Color perform() { return Color(R, G, B); }
};

struct Std_exception_on_error_policy
{
    static Color perform() { throw std::range_error("color does not exist"); }
};
}  // namespace Ex6
#endif