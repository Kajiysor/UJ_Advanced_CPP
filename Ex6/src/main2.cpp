#include "stack.h"

int main()
{
    {
        /// no checking policy

        auto stack1 = Ex6::Stack<int, 5>();
        stack1.pop();
        std::cout << "ok" << std::endl;

        /// abort on error policy

        auto stack2 = Ex6::Stack<int, 5, Ex6::Std_exception_on_error_policy>();
        stack2.pop();
        std::cout << "Error" << std::endl;
    }
    return 0;
}