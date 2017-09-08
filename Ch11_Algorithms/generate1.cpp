// Chapter 11 Algorithms -- generate
#include <cstdlib>
#include "algostuff.hpp"
using namespace std;


int main()
{
    list<int> coll;
    generate_n(back_inserter(coll),     // beginning of destination
               5,                       // count
               rand);                   // new value generator
    PRINT_ELEMENTS(coll);

    // overwrite with five new random numbers
    generate(coll.begin(), coll.end(), rand);
    PRINT_ELEMENTS(coll);
}
