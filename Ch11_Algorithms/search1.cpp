// Chapter 11 Algorithms -- search search_if
#include "algostuff.hpp"
using namespace std;


int main()
{
    deque<int> coll;
    list<int> subcoll;

    INSERT_ELEMENTS(coll, 1, 7);
    INSERT_ELEMENTS(coll, 1, 7);
    INSERT_ELEMENTS(subcoll, 3, 6);

    PRINT_ELEMENTS(coll,    "coll:    ");
    PRINT_ELEMENTS(subcoll, "subcoll: ");

    // search first occurrence of subcoll in coll
    deque<int>::iterator pos;
    pos = search(coll.begin(), coll.end(),        // range
                 subcoll.begin(), subcoll.end()); // subrange
    
    // loop while subcoll found a subrange of coll
    while(pos != coll.end()){
        // print position of first element
        cout << "subcoll found starting with element "
             << distance(coll.begin(), pos) + 1
             << endl;

        // search next occurence of subcoll
        ++pos;
        pos = search(pos, coll.end(),                   // range
                     subcoll.begin(), subcoll.end());   // subrange
    }
}
