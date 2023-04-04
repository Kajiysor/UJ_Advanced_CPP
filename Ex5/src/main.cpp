#include <iostream>
#include <vector>

#include "has_value_type.h"
#include "is_class.h"
#include "is_convertible.h"
#include "strip.h"

class A
{};

int main()
{
    // IsClass
    {
        std::cout << "IsClass<int>: " << Ex5::IsClass<int>::check << std::endl;
        std::cout << "IsClass<A>: " << Ex5::IsClass<A>::check << std::endl;
        std::cout << "IsClass<std::vector<double> >: " << Ex5::IsClass<std::vector<double> >::check << std::endl;
    }

    // HasValueType
    {
        std::cout << "HasValueType<int>: " << Ex5::HasValueType<int>::check << std::endl;
        std::cout << "HasValueType<A>: " << Ex5::HasValueType<A>::check << std::endl;
        std::cout << "HasValueType<std::vector<double> >: " << Ex5::HasValueType<std::vector<double> >::check << std::endl;
    }

    // IsConvertible
    {
        std::cout << "IsConvertible<int, double>: " << Ex5::IsConvertible<int, double>::check << std::endl;
        std::cout << "IsConvertible<double, int>: " << Ex5::IsConvertible<double, int>::check << std::endl;

        std::cout << "IsConvertible<double, int>: same_type:  " << Ex5::IsConvertible<double, int>::same_type << std::endl;

        std::cout << "IsConvertible<size_t, unsigned>: same_type:  " << Ex5::IsConvertible<size_t, unsigned int>::same_type
                  << std::endl;
        std::cout << "IsConvertible<std::vector<double>::value_type, double>: same_type:  "
                  << Ex5::IsConvertible<std::vector<double>::value_type, double>::same_type << std::endl;

        std::cout << "IsConvertible<std::vector<double>::iterator, double *>: same_type:  "
                  << Ex5::IsConvertible<std::vector<double>::iterator, double *>::same_type << std::endl;
    }

    // Strip
    {
        std::cout << "IsConvertible<Ex5::Strip<const int &>::base_t, int>: same_type: "
                  << Ex5::IsConvertible<Ex5::Strip<const int &>::base_t, int>::same_type << std::endl;
        std::cout << "IsConvertible<Ex5::Strip<const int &>::striped_t, const int>: same_type: "
                  << Ex5::IsConvertible<Ex5::Strip<const int &>::striped_t, const int>::same_type << std::endl;
    }

    return 0;
}