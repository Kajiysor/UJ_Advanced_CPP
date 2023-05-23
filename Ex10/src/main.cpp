#include <algorithm>
#include <execution>
#include <iostream>
#include <mutex>
#include <numeric>
#include <vector>

int main()
{
    // Execution policies
    {
        std::vector<int> v;
        for (int i = 0; i < 1000; ++i)
        {
            v.push_back(i);
        }
        int sum = 0;

        // std::execution::sequenced_policy

        // The execution policy type used as a unique type to disambiguate parallel algorithm overloading and require that
        // a parallel algorithm's execution may not be parallelized. The invocations of element access functions in
        // parallel algorithms invoked with this policy (usually specified as std::execution::seq) are indeterminately
        // sequenced in the calling thread.

        std::cout << "seq" << std::endl;
        std::for_each(std::execution::seq, std::begin(v), std::end(v), [&](int i) {
            std::cout << i << " ";
            sum += i * i;
        });
        std::cout << "sum: " << sum << " " << std::endl << std::endl;

        // std::execution::parallel_policy

        // The execution policy type used as a unique type to disambiguate parallel algorithm overloading and indicate that
        // a parallel algorithm's execution may be parallelized. The invocations of element access functions in parallel
        // algorithms invoked with this policy (usually specified as std::execution::par) are permitted to execute in
        // either the invoking thread or in a thread implicitly created by the library to support parallel algorithm
        // execution. Any such invocations executing in the same thread are indeterminately sequenced with respect to
        // each other.

        sum = 0;
        std::mutex m;

        std::cout << "par" << std::endl;
        std::for_each(std::execution::par, std::begin(v), std::end(v), [&](int i) {
            std::lock_guard<std::mutex> lock{m};
            std::cout << i << " ";
            sum += i * i;
        });
        std::cout << "sum: " << sum << " " << std::endl << std::endl;

        // std::execution::parallel_unsequenced_policy,

        // The execution policy type used as a unique type to disambiguate parallel algorithm overloading and indicate that
        // a parallel algorithm's execution may be parallelized, vectorized, or migrated across threads (such as by a
        // parent-stealing scheduler). The invocations of element access functions in parallel algorithms invoked with
        // this policy are permitted to execute in an unordered fashion in unspecified threads, and unsequenced with
        // respect to one another within each thread.

        std::cout << "par_unseq" << std::endl;
        std::atomic<int> summ{0};
        std::for_each(std::execution::par_unseq, std::begin(v), std::end(v), [&](int i) {
            std::cout << i << " ";
            summ.fetch_add(i * i, std::memory_order_relaxed);
        });
        std::cout << "sum: " << summ << " " << std::endl << std::endl;
    }

    // par
    {
        std::vector<int> vec(10'000'000);
        std::iota(vec.begin(), vec.end(), 0);
        std::vector<int> output;

        std::mutex m;
        const auto start = std::chrono::steady_clock::now();
        std::for_each(std::execution::par, vec.begin(), vec.end(), [&output, &m](int &elem) {
            if (elem % 2 == 0)
            {
                std::lock_guard<std::mutex> lock{m};
                output.push_back(elem);
            }
        });
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    // seq
    {
        std::vector<int> vec(10'000'000);
        std::iota(vec.begin(), vec.end(), 0);
        std::vector<int> output;

        const auto start = std::chrono::steady_clock::now();
        std::for_each(std::execution::seq, vec.begin(), vec.end(), [&output](int &elem) {
            if (elem % 2 == 0)
            {
                output.push_back(elem);
            }
        });
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** count if
     */
    std::cout << "count if" << std::endl;

    // par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::count_if(std::execution::par, vec.begin(), vec.end(), [](int i) { return i % 4 == 0; });
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    // seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::count_if(std::execution::seq, vec.begin(), vec.end(), [](int i) { return i % 4 == 0; });
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** remove if
     */
    std::cout << "remove if" << std::endl;

    // par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        std::remove_if(std::execution::par, vec.begin(), vec.end(), [](int i) { return i % 4 == 0; });
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    // seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        std::remove_if(std::execution::seq, vec.begin(), vec.end(), [](int i) { return i % 4 == 0; });
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
        for (int i = 0; i < 100; ++i)
        {
            std::cout << vec[i] << " ";
        }
        std::cout << std::endl;
    }

    /*
     ** min element
     */
    std::cout << "min element" << std::endl;

    // par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::min_element(std::execution::par, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    // seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::min_element(std::execution::seq, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** max element
     */
    std::cout << "max element" << std::endl;

    // par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::max_element(std::execution::par, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    // seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::max_element(std::execution::seq, vec.begin(), vec.end());
        std::cout << "result: " << std::distance(vec.begin(), result) << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    /*
     ** is sorted
     */
    std::cout << "is sorted" << std::endl;

    // par
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::is_sorted(std::execution::par, vec.begin(), vec.end());
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "par: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    // seq
    {
        std::vector<int> vec(100'000'000);
        for (int i = 0; i < 100'000'000; ++i)
        {
            vec.push_back(i);
        }

        const auto start = std::chrono::steady_clock::now();
        auto result = std::is_sorted(std::execution::seq, vec.begin(), vec.end());
        std::cout << "result: " << result << std::endl;
        const auto end = std::chrono::steady_clock::now();
        std::cout << "seq: " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    return 0;
}