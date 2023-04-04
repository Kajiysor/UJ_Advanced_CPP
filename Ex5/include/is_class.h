namespace Ex5
{
template <typename T>
class IsClass
{
    typedef char first;
    typedef struct
    {
        char c[2];
    } second;

    template <typename U>
    static first test(int U::*);

    template <typename U>
    static second test(...);

public:
    enum
    {
        check = (sizeof(test<T>(nullptr)) == sizeof(first))
    };
};
}  // namespace Ex5