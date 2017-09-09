// Chapter 11 Algorithms -- remove
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 2, 6);
    INSERT_ELEMENTS(coll, 4, 9);
    INSERT_ELEMENTS(coll, 1, 7);
    PRINT_ELEMENTS(coll,"coll:                ");
    
    // remove all elements with value 5
    vector<int>::iterator pos;
    pos = remove(coll.begin(), coll.end(),
                 5);

    PRINT_ELEMENTS(coll, "size not changed:    ");

    // erase the "removed" elements in the container
    coll.erase(pos, coll.end());
    PRINT_ELEMENTS(coll, "size changed:        ");

    // remove all elements less than 4
    coll.erase(remove_if(coll.begin(), coll.end(),  // range
                         [](int elem){ return elem<4; }
                        ),
                coll.end());
    PRINT_ELEMENTS(coll, "<4 removed:          ");
}
