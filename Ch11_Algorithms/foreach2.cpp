// Chapter 11 Algorithms -- for_each
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);

    // add 10 to each element
    for_each(coll.begin(), coll.end(),
             [](int& elem){ elem += 10; }
            );
    PRINT_ELEMENTS(coll);

    // add value of first element to each element
    for_each(coll.begin(), coll.end(),  // range
             [=](int& elem){ elem += coll.front(); }
            );
    PRINT_ELEMENTS(coll);
}
