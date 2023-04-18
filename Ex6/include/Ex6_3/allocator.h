#ifndef _allocator_
#define _allocator_

#include <algorithm>
#include <cstdio>

namespace Ex6
{
template <typename T, size_t N = 0>
struct Static_table_allocator
{
    typedef T rep_type[N];

    void init(rep_type &, size_t){};

    void expand_if_needed(rep_type &, size_t){};

    void shrink_if_needed(rep_type &, size_t){};

    void dealocate(rep_type &){};

    static size_t size() { return N; };
};

template <typename T, size_t N>
struct Dynamic_table_allocator
{
    typedef T *rep_type;
    size_t _size;

    void init(rep_type &rep, size_t n)
    {
        _size = n;
        rep = new T[_size];
    };

    void expand_if_needed(rep_type &, size_t){};

    void shrink_if_needed(rep_type &, size_t){};

    void dealocate(rep_type &rep) { delete[] rep; };

    [[nodiscard]] size_t size() const { return _size; };
};

template <typename T, size_t N>
struct Expandable_new_allocator
{
    typedef T *rep_type;
    size_t _size;

    void init(rep_type &rep, size_t n)
    {
        _size = n;
        rep = new T[_size];
    };

    void expand_if_needed(rep_type &rep, size_t top)
    {
        if (top == _size)
        {
            _size = 2 * _size;
            T *tmp = new T[_size];
            std::copy(rep, &rep[top], tmp);
            delete[] rep;
            rep = tmp;
        }
    };

    void shrink_if_needed(rep_type &size_t){};

    void dealocate(rep_type &rep) { delete[] rep; };

    [[nodiscard]] size_t size() const { return _size; };
};
}  // namespace Ex6

#endif