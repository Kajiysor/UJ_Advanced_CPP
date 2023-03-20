#include <set>

namespace Ex3
{
template <typename Iter>
void reversePrint(Iter a, Iter b)
{
    while (a != b)
    {
        std::cout << *a << " ";
        ++a;
    }
}
}  // namespace Ex3
