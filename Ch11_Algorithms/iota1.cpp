// Chapter 11 Algorithms -- iota
#include "algostuff.hpp"
using namespace std;


int main()
{
    array<int,10> coll;
    
    iota(coll.begin(), coll.end(), 42);

    PRINT_ELEMENTS(coll, "coll:  ");
}
