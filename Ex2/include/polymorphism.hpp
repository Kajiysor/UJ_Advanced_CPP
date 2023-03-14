#include <iostream>

namespace Ex2
{

// Dynamic polymorphism

class Base
{
public:
    virtual void f() { std::cout << "Base::f()" << std::endl; }
    virtual void g() { std::cout << "Base::g()" << std::endl; }
    virtual void h() { std::cout << "Base::h()" << std::endl; }
};

class Derived : public Base
{
public:
    void f() override { std::cout << "Derived::f()" << std::endl; }
    void g1() { std::cout << "Derived::g1()" << std::endl; }
};

// Static polymorphism

template <typename T>
class StaticBase
{
public:
    void f() { static_cast<T *>(this)->f_impl(); }
    void g() { static_cast<T *>(this)->g_impl(); }
    void h() { static_cast<T *>(this)->h_impl(); }
};

class StaticDerived : public StaticBase<StaticDerived>
{
public:
    void f_impl() { std::cout << "StaticDerived::f()" << std::endl; }
    void g_impl() { std::cout << "StaticDerived::g()" << std::endl; }
    void h_impl() { std::cout << "StaticDerived::h()" << std::endl; }
};
}  // namespace Ex2