namespace Ex4::SumTraits
{
template <typename T>
struct sum_traits;

template <>
struct sum_traits<char>
{
    typedef int sum_type;
};
template <>
struct sum_traits<int>
{
    typedef long int sum_type;
};
template <>
struct sum_traits<float>
{
    typedef float sum_type;
};
template <>
struct sum_traits<double>
{
    typedef double sum_type;
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end)
{
    typedef typename sum_traits<T>::sum_type sum_type;
    sum_type total = sum_type();
    while (beg != end)
    {
        total += *beg;
        beg++;
    }
    return total;
}
}  // namespace Ex4::SumTraits