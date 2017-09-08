// Chapter 11 Algorithms
#include "algostuff.hpp"
using namespace std;


int main()
{
    list<int> coll;

    INSERT_ELEMENTS(coll,2,7);
    INSERT_ELEMENTS(coll,4,9);
    PRINT_ELEMENTS(coll, "coll:  ");

    // replace all elements with value 6 with 42
    replace(coll.begin(), coll.end(),
            6,
            42);
    PRINT_ELEMENTS(coll,"coll:  ");

    // replace all elements with value less than 5 with 0
    replace_if(coll.begin(), coll.end(),        // range
               [](int elem){ return elem<5; },  // criterion for replacement
               0);                              // new value
    PRINT_ELEMENTS(coll, "coll:  ");
}
