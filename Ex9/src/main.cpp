#include "smart_ptrs.h"
#include "song_factory.h"
#include "weak_ptr.h"

int main()
{
    // Smart pointers
    {
        /*
         * unique_ptr: allows exactly one owner of the underlying pointer. Use as the default choice for POCO unless you
         * know for certain that you require a shared_ptr. Can be moved to a new owner, but not copied or shared.
         */

        Ex9::testUnique();
        std::cout << "after testUnique()" << std::endl;

        /*
         * shared_ptr: reference-counted smart pointer. Use when you want to assign one raw pointer to multiple owners, for
         * example, when you return a copy of a pointer from a container but want to keep the original. The raw pointer is
         * not deleted until all shared_ptr owners have gone out of scope or have otherwise given up ownership.
         */

        auto shared = std::make_shared<Ex9::Test>();
        Ex9::testShared(shared);
        std::cout << "after testShared()" << std::endl;
    }

    // Smart ptrs sizes
    {
        // check if normal ptr is the same size as smart ptr
        std::cout << "sizeof(int*): " << sizeof(int *) << std::endl;
        std::cout << "sizeof(std::unique_ptr<int>): " << sizeof(std::unique_ptr<int>) << std::endl;
        std::cout << "sizeof(std::shared_ptr<int>): " << sizeof(std::shared_ptr<int>) << std::endl;
    }

    // Song factory
    {
        std::cout << "before song test" << std::endl;
        Ex9::test();
        std::cout << "after song test" << std::endl;
        std::cout << "---" << std::endl;
        Ex9::songVector();
    }

    // Unique ptr
    {
        // to initialize object
        // template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args );
        auto obj = std::make_unique<Ex9::Test>();

        // to initialize table
        // template< class T > unique_ptr<T> make_unique( std::size_t size );
        auto t = std::make_unique<int[]>(5);
    }

    // Shared ptr
    {
        std::cout << "first ptr" << std::endl;
        auto ptr = std::make_shared<Ex9::Test>();
        ptr->hello();
        std::cout << "second ptr" << std::endl;
        ptr->hello();
        std::cout << "after call" << std::endl;
    }

    // Weak ptr
    {
        // empty definition
        auto sptr = std::make_shared<int>(1);

        // get pointer to data without taking ownership
        std::weak_ptr<int> weak1 = sptr;

        auto pc = new Ex9::PointerContainer(weak1);
        pc->checkPtr();

        // deletes managed object, acquires new pointer
        sptr = std::make_shared<int>(2);
        pc->checkPtr();
    }

    return 0;
}