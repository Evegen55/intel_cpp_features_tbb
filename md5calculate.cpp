#include "md5calculate.h"
#include <tbb/blocked_range.h>

#include <iostream>
#include <sstream>
#include <thread>

MD5Calculate::MD5Calculate()
{

}

void MD5Calculate::operator()(const tbb::blocked_range<int> &range) const
{
    std::stringstream stream;

    for(int i = range.begin(); i != range.end(); i++)
    {
        if(i%1000 == 0)
        {
            std::cout << "counter is: " << i << " and thread name is: " << std::this_thread::get_id << std::endl;
        }
    }
}
