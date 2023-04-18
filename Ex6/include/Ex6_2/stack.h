#ifndef _stack_
#define _stack_

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include "checking_policy.h"

namespace Ex6
{
template <typename T = int, size_t N = 100, typename Checking_policy = No_checking_policy>
class Stack
{
    T _rep[N];
    size_t _top;

public:
    explicit Stack(size_t n = N) : _top(0){};

    void push(const T &val)
    {
        Checking_policy::check_push(_top, N);
        _rep[_top++] = val;
    }

    void pop()
    {
        Checking_policy::check_pop(_top);
        --_top;
    }

    T top() const
    {
        Checking_policy::check_top(_top);
        return &_rep[_top - 1];
    }

    T &top()
    {
        Checking_policy::check_top(_top);
        return _rep[_top - 1];
    }

    bool is_empty() { return !_top; }
};
}  // namespace Ex6

#endif