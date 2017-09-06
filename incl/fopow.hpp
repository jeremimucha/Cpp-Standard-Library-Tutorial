// Chapter 10 Function Objects -- user defined function objects
#include <cmath>


template<typename T1, typename T2>
struct fopow
{
    T1 operator()(T1 base, T2 exp) const
    {
        return std::pow(base, exp);
    }
};
