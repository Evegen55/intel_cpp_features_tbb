#include <iostream>

#include <tbb/parallel_for.h>
#include <tbb/task_scheduler_init.h>
#include "tbb/blocked_range.h"
#include <tbb/tbb.h>

#include <pstl/algorithm>
#include <pstl/execution>
#include <iostream>
#include <vector>

#include <md5calculate.h>

using namespace std;

int main()
{
    //fig_1_04.cpp
    tbb::parallel_invoke(
        []() { std::cout << " Hello " << std::endl; },
        []() { std::cout << " TBB! " << std::endl; }
      );

    //fig_1_05.cpp
    std::vector<std::string> v = { " Hello ", " Parallel STL! " };
      std::for_each(pstl::execution::par, v.begin(), v.end(),
        [](std::string& s) { std::cout << s << std::endl; }
      );

    //some example
    tbb::tick_count t0 = tbb::tick_count::now();
    tbb::task_scheduler_init init;
    tbb::parallel_for(tbb::blocked_range<int>(1000000, 8999999), MD5Calculate());
    std::cout << "Time : "
              << (tbb::tick_count::now()-t0).seconds()
              << " seconds" << std::endl;
    return 0;
}
