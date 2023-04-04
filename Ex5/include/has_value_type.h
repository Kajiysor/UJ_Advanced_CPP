namespace Ex5
{
template <typename T>
class HasValueType
{
    typedef char one;
    typedef struct
    {
        char c[2];
    } two;

    template <typename U>
    static one test(typename U::value_type);

    template <typename U>
    static two test(...);

public:
    enum
    {
        check = (sizeof(test<T>(0)) == sizeof(one))
    };
};
}  // namespace Ex5