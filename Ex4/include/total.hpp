namespace Ex4::Total
{
template <typename T>
struct sum_traits;

template <>
struct sum_traits<char>
{
    typedef int sum_type;

    static sum_type zero() { return 0; }
};

template <>
struct sum_traits<int>
{
    typedef int sum_type;

    static sum_type zero() { return 0; }
};

template <>
struct sum_traits<float>
{
    typedef double sum_type;

    static sum_type zero() { return 0.0; }
};

template <>
struct sum_traits<double>
{
    typedef double sum_type;

    static sum_type zero() { return 0.0; }
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end)
{
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_traits<T>::zero();
    while (beg != end)
    {
        total += *beg;
        beg++;
    }
    return total;
}
}  // namespace Ex4