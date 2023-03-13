// accumulate function with two iterator arguments
template <typename InputIterator, typename T>
T accumulate(InputIterator first, InputIterator last, T init)
{
    for (; first != last; ++first)
    {
        init = init + *first;
    }
    return init;
}
