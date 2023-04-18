#include "col_fact.h"

int main()
{
    Ex6::ColorFactory factory1;
    Ex6::ColorFactory<Ex6::Default_on_error_policy<>> factory2;
    Ex6::ColorFactory<Ex6::Default_on_error_policy<1, 1, 1>> factory3;

    try
    {
        std::cout << "factory1" << std::endl;
        factory1.returnColor("red").print();
    }
    catch (...)
    {
        std::cout << "Exception!" << std::endl;
    }

    try
    {
        std::cout << "factory2" << std::endl;
        factory2.returnColor("red").print();
    }
    catch (...)
    {
        std::cout << "Exception!" << std::endl;
    }

    try
    {
        std::cout << "factory3" << std::endl;
        factory3.returnColor("red").print();
    }
    catch (...)
    {
        std::cout << "Exception!" << std::endl;
    }
    return 0;
}