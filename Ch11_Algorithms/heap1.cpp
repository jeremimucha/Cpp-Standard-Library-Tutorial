// Chapter 11 Algorithms -- make_heap push_head pop_heap sort_heap
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll;

    INSERT_ELEMENTS( coll, 3, 7 );
    INSERT_ELEMENTS( coll, 5, 9 );
    INSERT_ELEMENTS( coll, 1, 4 );

    PRINT_ELEMENTS( coll, "on entry:            " );
    
    // convert collection into a heap
    make_heap( coll.begin(), coll.end() );
    PRINT_ELEMENTS( coll, "after make_heap():   " );

    // pop next element out of the heap
    pop_heap( coll.begin(), coll.end() );
    coll.pop_back();

    PRINT_ELEMENTS( coll, "after pop_heap():    " );

    // push new element into the heap
    coll.push_back( 17 );
    push_heap(coll.begin(), coll.end() );

    PRINT_ELEMENTS( coll, "after push_heap():   " );

    // convert heap into a sorted collection
    // - NOTE: after the call it is no longer a heap
    sort_heap( coll.begin(), coll.end() );

    PRINT_ELEMENTS( coll, "after sort_heap():   " );
}
