#include "checking_policy.h"
#include "stack.h"

int main()
{
    Ex6::Stack<int, 1, Ex6::Abort_on_error_policy, Ex6::Expandable_new_allocator> s1(1);
    Ex6::Stack<int, 1, Ex6::Std_exception_on_error_policy, Ex6::Dynamic_table_allocator> s2(1);

    s1.push(0);
    s1.push(1);
    std::cout << "ok" << std::endl;

    s2.push(0);
    s2.push(1);
    std::cout << "Error" << std::endl;

    return 0;
}