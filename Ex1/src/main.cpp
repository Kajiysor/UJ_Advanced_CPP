#include <templates.hpp>

int main()
{
    std::cout << "===== Testing max =====" << std::endl;
    std::cout << Ex1::max<int>(7, 5) << std::endl;
    std::cout << Ex1::max<double>(3.1415, 2.71) << std::endl;
    std::cout << Ex1::max<std::string>("Ania", "Basia") << std::endl;
    std::cout << "===== Testing convert =====" << std::endl;
    std::cout << Ex1::convert<int>(3.1415) << std::endl;
    std::cout << Ex1::convert<double>(7) << std::endl;
    std::cout << Ex1::convert<std::string>(3.1415) << std::endl;
    std::cout << "===== Testing dot =====" << std::endl;
    std::cout << Ex1::dot<3>(std::array<int, 3>{1, 2, 3}, std::array<int, 3>{4, 5, 6}) << std::endl;
    std::cout << Ex1::dot<3>(std::array<double, 3>{1.1, 2.2, 3.3}, std::array<double, 3>{4.4, 5.5, 6.6}) << std::endl;
    std::cout << Ex1::dot<3>(std::array<float, 3>{1.1f, 2.2f, 3.3f}, std::array<float, 3>{4.4f, 5.5f, 6.6f}) << std::endl;
    std::cout << "===== Testing foo =====" << std::endl;
    Ex1::foo(Ex1::Bar<7>());
    Ex1::foo(Ex1::Bar<15>());
    Ex1::foo(Ex1::Bar<-3>());
    std::cout << "===== Testing Stack =====" << std::endl;
    Ex1::Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << Ex1::sum(stack) << std::endl;
    return 0;
}