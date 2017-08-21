// predefined function object templates in the <functional> header
#include <deque>
#include <algorithm>
#include <functional>
#include <iostream>
#include <print.hpp>
using namespace std;


int main()
{
    deque<int> coll = {1,2,3,5,7,11,13,17,19};
    PRINT_ELEMENTS(coll, "initialized: ");
    
    // negate all values in coll
    transform(coll.cbegin(), coll.cend(),   // source
              coll.begin(),                 // destination
              negate<int>());
    PRINT_ELEMENTS(coll, "negated:     ");

    // square all values in coll
    transform(coll.cbegin(), coll.cend(),   // source first
              coll.cbegin(),                // source second
              coll.begin(),                 // destination
              multiplies<int>());           // operation
    PRINT_ELEMENTS(coll, "squared:     ");
}
