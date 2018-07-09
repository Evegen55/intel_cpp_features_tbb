#include <iostream>

#include <tbb/parallel_for.h>
#include <tbb/task_scheduler_init.h>
#include "tbb/blocked_range.h"
#include <md5calculate.h>

using namespace std;

int main()
{
    tbb::task_scheduler_init init;
    tbb::parallel_for(tbb::blocked_range<int>(1000000, 8999999), MD5Calculate());
    return 0;
}
