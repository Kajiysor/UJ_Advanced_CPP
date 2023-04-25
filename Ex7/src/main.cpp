#include <cmath>
#include <iostream>
#include <vector>

#include "factorial.h"
#include "faster_pow.h"
#include "pow.h"
#include "sin.h"
#include "vectors.h"

int main()
{
    // factorial
    std::cout << "factorial<5>().val: " << Ex7::factorial<5>().val << std::endl;

    // pow
    std::cout << "pow<2, 8>().val: " << Ex7::pow<2, 8>().val << std::endl;

    // fastPow
    std::cout << "fastPow<8>(2): " << Ex7::fastPow<8>(2) << std::endl;

    // sin
    std::cout << "sin<2>(2.3): " << Ex7::sin<2>(2.3) << std::endl;

    // inner
    auto vector1 = new double[3];
    vector1[0] = 1.0;
    vector1[1] = 2.0;
    vector1[2] = 3.0;

    auto vector2 = new double[3];
    vector2[0] = 1.0;
    vector2[1] = 2.0;
    vector2[2] = 3.0;

    std::cout << "inner<3>(vector1, vector2): " << Ex7::inner<3>(vector1, vector2) << std::endl;
    std::cout << "dot<3, double>(vector1, vector2): " << Ex7::dot<3, double>(vector1, vector2) << std::endl;

    return 0;
}