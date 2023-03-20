#include <cstring>

namespace Ex3
{
template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

template <typename T>
T *max(T *a, T *b)
{
    return *a > *b ? a : b;
}

template <typename T>
T max(T *data_size, std::size_t n)
{
    T max = data_size[0];
    for (std::size_t i = 1; i < n; ++i)
    {
        if (data_size[i] > max)
        {
            max = data_size[i];
        }
    }
    return max;
}

template <>
char *max(char *a, char *b)
{
    return std::strcmp(a, b) > 0 ? a : b;
}

template <>
const char *max(const char *a, const char *b)
{
    return std::strcmp(a, b) > 0 ? a : b;
}

template <typename T>
const T *max(T *a, const T *b)
{
    return *a > *b ? a : const_cast<T *>(b);
}

template <>
const char *max(char *a, const char *b)
{
    return std::strcmp(a, b) > 0 ? a : b;
}

}  // namespace Ex3