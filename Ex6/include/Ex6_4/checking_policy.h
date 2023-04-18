
#ifndef _checking_policy_
#define _checking_policy_

#include <cstdio>
#include <iostream>

namespace Ex6
{
struct No_checking_policy
{
    static void check_push(size_t, size_t){};

    static void check_pop(size_t){};

    static void check_top(size_t){};
};

struct Abort_on_error_policy
{
    static void check_push(size_t top, size_t size)
    {
        if (top >= size)
        {
            std::cout << "trying to push elemnt on full stack: aborting" << std::endl;
            abort();
        }
    };

    static void check_pop(size_t top)
    {
        if (top == 0)
        {
            std::cout << "trying to pop an empty stack: aborting" << std::endl;
            abort();
        }
    };

    static void check_top(size_t top)
    {
        if (top == 0)
        {
            std::cout << "trying to read from empty stack: aborting" << std::endl;
            abort();
        }
    };
};

struct Std_exception_on_error_policy
{
    static void check_push(size_t top, size_t size)
    {
        if (top >= size)
        {
            throw std::range_error("over the top");
        }
    };

    static void check_pop(size_t top)
    {
        if (top == 0)
        {
            throw std::range_error("poping empty");
        }
    };

    static void check_top(size_t top)
    {
        if (top == 0)
        {
            throw std::range_error("reading empty");
        }
    };
};
}  // namespace Ex6

#endif