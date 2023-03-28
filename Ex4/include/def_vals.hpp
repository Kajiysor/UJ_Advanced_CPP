namespace Ex4::DefVals
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
    typedef double sum_type;
};
template <>
struct sum_traits<double>
{
    typedef double sum_type;
};

template <typename Traits, typename T>
typename Traits::sum_type sum(T *beg, T *end)
{
    typedef typename Traits::sum_type sum_type;
    sum_type total = sum_type();
    while (beg != end)
    {
        total += *beg;
        beg++;
    }
    return total;
};

template <typename T>
typename sum_traits<T>::sum_type sum(T *beg, T *end)
{
    return sum<sum_traits<T>, T>(beg, end);
}

struct char_sum
{
    typedef char sum_type;
};
}  // namespace Ex4::DefVals