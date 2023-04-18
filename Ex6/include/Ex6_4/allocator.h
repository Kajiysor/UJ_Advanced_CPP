#ifndef _allocator_
#define _allocator_

#include <algorithm>
#include <cstdio>

namespace Ex6
{
template <typename T, size_t N = 0>
class Static_table_allocator
{
protected:
    typedef T rep_type[N];
    rep_type _rep;

    void init(size_t){};

    void expand_if_needed(size_t){};

    void shrink_if_needed(size_t){};

    void dealocate(){};

    static size_t size() { return N; };
};

template <typename T, size_t N>
class Dynamic_table_allocator
{
protected:
    typedef T *rep_type;
    rep_type _rep;
    size_t _size;

    void init(size_t n)
    {
        _size = n;
        _rep = new T[_size];
    };

    void expand_if_needed(size_t){};

    void shrink_if_needed(size_t){};

    void dealocate() { delete[] _rep; };

    size_t size() const { return _size; };

public:
    void resize(size_t n)
    {
        T *tmp = new T[n];
        std::copy(_rep, &_rep[(_size < n) ? _size : n], tmp);
        delete[] _rep;
        _rep = tmp;
        _size = n;
    }
};

template <typename T, size_t N>
class Expandable_new_allocator
{
protected:
    typedef T *rep_type;
    rep_type _rep;
    size_t _size;

    void init(size_t n)
    {
        _size = n;
        _rep = new T[_size];
    };

    void expand_if_needed(size_t top)
    {
        if (top == _size)
        {
            _size = 2 * _size;
            T *tmp = new T[_size];
            std::copy(_rep, &_rep[top], tmp);
            delete[] _rep;
            _rep = tmp;
        }
    };

    void shrink_if_needed(size_t){};

    void dealocate() { delete[] _rep; };

    [[nodiscard]] size_t size() const { return _size; };
};
}  // namespace Ex6

#endif