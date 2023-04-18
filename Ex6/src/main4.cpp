#include "checking_policy.h"
#include "stack.h"

int main()
{
    Ex6::Stack<int, 2, Ex6::Std_exception_on_error_policy, Ex6::Dynamic_table_allocator> s(2);
    s.resize(4);

    s.push(1);
    s.push(2);
    s.push(3);

    return 0;
}