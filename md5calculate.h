#ifndef MD5CALCULATE_H
#define MD5CALCULATE_H

#include <tbb/blocked_range.h>
class MD5Calculate
{
public:
    MD5Calculate();
    void operator() (const tbb::blocked_range<int>& range) const;
};

#endif // MD5CALCULATE_H
