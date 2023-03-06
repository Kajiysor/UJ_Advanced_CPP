#include <iostream>
#include <array>
#include <vector>

namespace Ex1
{
    template <typename T>
    T max(T a, T b)
    {
        return a > b ? a : b;
    }

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

    template <std::size_t N, typename T>
    T dot(const std::array<T, N> &a, const std::array<T, N> &b)
    {
        T result = T();
        for (std::size_t i = 0; i < N; ++i)
        {
            result += a[i] * b[i];
        }
        return result;
    }

    template <template <int N> class T, int K>
    void foo(T<K> t)
    {
        std::cout << K << std::endl;
    }

    template <int N>
    class Bar
    {
    };

    template <typename T>
    class Stack
    {
    public:
        typedef T value_type;

        void push(const T &t)
        {
            s.push_back(t);
        }

        T pop()
        {
            T t = s.back();
            s.pop_back();
            return t;
        }

        bool empty() const
        {
            return s.empty();
        }

    private:
        std::vector<T> s;
    };

    template <typename T>
    decltype(auto) sum(T t)
    {
        typename T::value_type sum = 0;
        while (!t.empty())
        {
            sum += t.pop();
        }
        return sum;
    }

}