namespace Ex5
{
template <typename T>
struct Strip
{
    typedef T arg_t;
    typedef T striped_t;
    typedef T base_t;
    typedef const T const_type;

    typedef T &ref_type;
    typedef T &ref_base_type;
    typedef const T &const_ref_type;
};

template <typename T>
struct Strip<T const>
{
    typedef const T arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef T const const_type;

    typedef T const &ref_type;
    typedef T &ref_base_type;
    typedef T const &const_ref_type;
};

template <typename T>
struct Strip<T &>
{
    typedef T &arg_t;
    typedef T striped_t;
    typedef typename Strip<T>::base_t base_t;
    typedef base_t const const_type;

    typedef T ref_type;
    typedef base_t &ref_base_type;
    typedef base_t const &const_ref_type;
};
}  // namespace Ex5