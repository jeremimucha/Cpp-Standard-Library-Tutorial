// Chapter 11 Algorithms -- adjacent_difference
#include "algostuff.hpp"
using namespace std;


int main()
{
    deque<int> coll;

    INSERT_ELEMENTS( coll, 1, 6 );
    PRINT_ELEMENTS( coll );

    // print all differences between elements
    adjacent_difference( coll.cbegin(), coll.cend(),
                         ostream_iterator<int>(cout, " ") );
    cout << endl;

    // print all sums with the predecessors
    adjacent_difference( coll.cbegin(), coll.cend(),
                         ostream_iterator<int>(cout, " "),
                         plus<int>() );
    cout << endl;

    // print all products between elements
    adjacent_difference( coll.cbegin(), coll.cend(),
                         ostream_iterator<int>(cout, " "),
                         multiplies<int>() );
    cout << endl;
}
