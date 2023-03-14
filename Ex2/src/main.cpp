#include <algorithm>
#include <functional>
#include <memory>
#include <vector>

#include "accumulate.hpp"
#include "polymorphism.hpp"
#include "sequence_gen.hpp"

int main()
{
    // Dynamic polymorphism
    std::unique_ptr<Ex2::Base> b = std::make_unique<Ex2::Derived>();
    b->f();  // Derived::f()
    b->g();  // Base::g()
    b->h();  // Base::h()
    // b->g1(); // error: ‘class Ex2::Base’ has no member named ‘g1’
    // static_cast<Derived *>(b.get())->g1(); // Derived::g1()

    // Static polymorphism
    Ex2::StaticDerived sd;
    sd.f();  // StaticDerived::f()
    sd.g();  // StaticDerived::g()
    sd.h();  // StaticDerived::h()
    // sd.g1(); // error: ‘class Ex2::StaticDerived’ has no member named ‘g1’
    // static_cast<StaticDerived *>(b.get())->g1(); // error: invalid static_cast from type ‘Ex2::Base*’ to type
    // ‘Ex2::StaticDerived*’

    // Accumulate
    std::vector<int> v1 = {1, 2, 3, 4, 5};
    std::cout << std::endl << "accumulate(): " << Ex2::accumulate(v1.begin(), v1.end(), 0) << std::endl;  // 15

    // Sequence generator
    std::vector<int> v2(20);
    std::generate_n(v2.begin(), v2.size(), Ex2::SequenceGen<int>(1, 2));
    std::vector<int>::iterator it =
            std::find_if(v2.begin(), v2.end(), std::bind(std::greater<int>(), std::placeholders::_1, 4));
    std::cout << std::endl << "*it: " << *it << std::endl;

    return 0;
}