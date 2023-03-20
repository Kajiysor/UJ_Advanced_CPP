#include <iostream>

#include "convert.hpp"
#include "max.hpp"
#include "set.hpp"
#include "stack.hpp"
#include "stl_stack.hpp"

int main()
{
    int i, j = 5;

    double x[5] = {1, 2, 4, 0, 3};

    char *p1 = new char[5];
    char *p2 = new char[5];

    strncpy(p1, "ania", 5);
    strncpy(p2, "asia", 5);

    /// T max(T a, T b)
    std::cout << Ex3::max(i, j) << std::endl;

    /// T *max(T *a, T *b)
    std::cout << *Ex3::max(&i, &j) << std::endl;

    /// T max(T *data, size_t n)
    std::cout << Ex3::max(x, 5) << std::endl;

    /// const char *max(const char *a, const char *b)
    std::cout << Ex3::max("asia", "ania") << std::endl;

    /// char *max(char *a, char *b)
    std::cout << Ex3::max(p1, p2) << std::endl;

    /// const T *max(char *a, const char *b)
    std::cout << Ex3::max(p1, "asia") << std::endl;

    // convert
    std::cout << Ex3::convert<int>(3.14) << std::endl;
    std::cout << Ex3::convert<double>(3) << std::endl;
    std::cout << Ex3::convert<std::string>(3.14) << std::endl;

    // stack
    std::cout << typeid(Ex3::Stack<int, 666>).name() << std::endl;
    std::cout << typeid(Ex3::Stack<float *, 25>).name() << std::endl;
    std::cout << typeid(Ex3::Stack<double, 33>).name() << std::endl;
    std::cout << typeid(Ex3::Stack<int *, 66>).name() << std::endl;
    std::cout << typeid(Ex3::Stack<double, 666>).name() << std::endl;
    std::cout << typeid(Ex3::Stack<double *, 44>).name() << std::endl;

    // stl_stack
    Ex3::StlStack<int, 100> stl_stack;
    Ex3::StlStack<int, 0, std::vector<int>> stl_stack2;

    stl_stack.push(1);

    std::cout << stl_stack.pop() << std::endl;

    stl_stack2.push(2);

    std::cout << stl_stack2.pop() << std::endl;

    // set
    std::set<int, std::greater<>> s;

    s.insert(17);
    s.insert(21);
    s.insert(19);

    Ex3::reversePrint(s.begin(), s.end());

    return 0;
}