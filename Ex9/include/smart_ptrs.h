#include <iostream>
#include <memory>

namespace Ex9
{
class Test
{
public:
    static void hello() { std::cout << "hello" << std::endl; }
    ~Test() { std::cout << "destruction" << std::endl; }
};

void testUnique()
{
    auto obj = std::make_unique<Test>();
    obj->hello();
}

void testShared(const std::shared_ptr<Test> ptr)
{
    ptr->hello();
}
}  // namespace Ex9