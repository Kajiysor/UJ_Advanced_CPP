namespace Ex5
{
template <typename T, typename U>
class IsConvertible
{
    typedef char first;
    typedef struct
    {
        char c[2];
    } second;

    static first test(U);

    static second test(...);

    static T makeT();

public:
    enum
    {
        check = sizeof(test(makeT())) == sizeof(first),
        same_type = false
    };
};

template <typename T>
class IsConvertible<T, T>
{
public:
    enum
    {
        check = true,
        same_type = true
    };
};
}  // namespace Ex5