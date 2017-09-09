// Chapter 11 Algorithms -- rotate_copy
#include "algostuff.hpp"
using namespace std;


int main()
{
    set<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll);

    // print elements rotated one element to the left
    set<int>::const_iterator pos = next(coll.cbegin());
    rotate_copy(coll.cbegin(),      // beginning of source
                pos,                // new first element
                coll.cend(),        // end of source
                ostream_iterator<int>(cout," "));   // destination
    cout << endl;

    // print elements rotated two elements to the right
    pos = coll.cend();
    advance(pos, -2);
    rotate_copy(coll.cbegin(),           // beginning of source
                pos,                     // new first element
                coll.cend(),             // end of source
                ostream_iterator<int>(cout," "));    // destination
    cout << endl;

    // print elements rotated so that element with value 4 is the beginning
    rotate_copy(coll.cbegin(),
                coll.find(4),
                coll.cend(),
                ostream_iterator<int>(cout," "));
    cout << endl;
}
