#include <vector>

namespace Ex3
{
template <typename T, int N = 100, typename R = T *>
class StlStack;

template <typename T, int N>
class StlStack<T, N, T *>
{
public:
    StlStack() = default;

    void push(const T &t) { s.push_back(t); }

    T pop()
    {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }

    bool empty() const { return s.empty(); }

    std::size_t size() const { return s.size(); }

private:
    std::vector<T> s;
};

template <typename T, int N>
class StlStack<T, N, std::vector<T>>
{
public:
    StlStack() = default;

    void push(const T &t) { s.push_back(t); }

    T pop()
    {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }

    bool empty() const { return s.empty(); }

    std::size_t size() const { return s.size(); }

private:
    std::vector<T> s;
};

template <typename T, int N>
class StlStack<T, N, std::vector<T> &>
{
public:
    StlStack() = default;

    void push(const T &t) { s.push_back(t); }

    T pop()
    {
        T t = s.back();
        s.pop_back();
        return t;
    }

    T top() const { return s.back(); }

    bool empty() const { return s.empty(); }

    std::size_t size() const { return s.size(); }

private:
    std::vector<T> &s;
};

}  // namespace Ex3
