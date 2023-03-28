#include <cstring>

#include "categories.hpp"
#include "def_vals.hpp"
#include "sum_iters.hpp"
#include "sum_traits.hpp"
#include "total.hpp"

int main()
{
    char name[] = "Val";
    int numbers[] = {1, 2, 3};
    float numbers2[] = {1.1, 2.2, 3.3};
    double numbers3[] = {1.1, 2.2, 3.3};
    auto length = 3;
    // Sum Traits
    {
        // char
        std::cout << Ex4::SumTraits::sum(name, &name[length]) << std::endl;

        // int
        std::cout << Ex4::SumTraits::sum(numbers, &numbers[length]) << std::endl;

        // double
        std::cout << Ex4::SumTraits::sum(numbers2, &numbers2[length]) << std::endl;
    }
    // Total
    {
        // char
        std::cout << Ex4::Total::sum(name, &name[length]) << std::endl;

        // int
        std::cout << Ex4::Total::sum(numbers, &numbers[length]) << std::endl;

        // float
        std::cout << Ex4::Total::sum(numbers2, &numbers2[length]) << std::endl;

        // double
        std::cout << Ex4::Total::sum(numbers3, &numbers3[length]) << std::endl;
    }
    // Def Vals
    {
        // char
        std::cout << (int)Ex4::DefVals::sum(name, &name[length]) << std::endl;
        std::cout << (int)Ex4::DefVals::sum<Ex4::DefVals::char_sum>(name, &name[length]) << std::endl;
        std::cout << (int)Ex4::DefVals::sum<char>(name, &name[length]) << std::endl;

        // int
        std::cout << Ex4::DefVals::sum(numbers, &numbers[length]) << std::endl;

        // float
        std::cout << Ex4::DefVals::sum(numbers2, &numbers2[length]) << std::endl;

        // double
        std::cout << Ex4::DefVals::sum(numbers3, &numbers3[length]) << std::endl;
    }
    // Sum Iters
    {
        // char
        std::cout << Ex4::SumIters::sum(name, &name[length]) << std::endl;

        // int
        std::cout << Ex4::SumIters::sum(numbers, &numbers[length]) << std::endl;

        // float
        std::cout << Ex4::SumIters::sum(numbers2, &numbers2[length]) << std::endl;

        // double
        std::cout << Ex4::SumIters::sum(numbers3, &numbers3[length]) << std::endl;
    }
    // Categories
    {
        std::list<int> testList;
        Ex4::Categories::operation(testList.begin());

        int testArr[3];
        Ex4::Categories::operation(testArr);
    }
    return 0;
}