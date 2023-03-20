#include <string>

namespace Ex3
{
template <typename T, typename U>
T convert(U u)
{
    try
    {
        return static_cast<T>(u);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return T();
    }
}

template <>
std::string convert<std::string>(double d)
{
    return std::to_string(d);
}

template <>
int convert<int, double>(double u)
{
    return static_cast<int>(u);
}

template <>
double convert<double, int>(int u)
{
    return static_cast<double>(u);
}
}  // namespace Ex3