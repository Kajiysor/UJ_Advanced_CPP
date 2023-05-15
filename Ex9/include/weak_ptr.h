#include <iostream>
#include <memory>

namespace Ex9
{
class PointerContainer
{
private:
    std::weak_ptr<int> weak;

public:
    explicit PointerContainer(std::weak_ptr<int> weak) : weak(weak) {}

    void checkPtr()
    {
        if (weak.expired())
            std::cout << "expired" << std::endl;
        else
            std::cout << "value is " << *weak.lock() << std::endl;
    }
};
}  // namespace Ex9