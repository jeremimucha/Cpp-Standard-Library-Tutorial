// Chapter 11 Algorithms -- accumulate
#include "algostuff.hpp"
using namespace std;

int main()
{
    vector<int> coll;

    INSERT_ELEMENTS( coll, 1, 9 );
    PRINT_ELEMENTS( coll );

    // process sum of elements
    cout << "sum: "
         << accumulate( coll.cbegin(), coll.cend(), // range
                        0 )                         // initial value
         << endl;

    // process sum of elements less 100
    cout << "sum: "
         << accumulate( coll.cbegin(), coll.cend(), -100 )
         << endl;

    // process product of elements
    cout << "product: "
         << accumulate( coll.cbegin(), coll.cend(), // range
                        1,                          // initial value
                        multiplies<int>() )         // operation
         << endl;

    // process product of elements ( use 0 as initial value )
    cout << "product: "
         << accumulate( coll.cbegin(), coll.cend(),
                        0,
                        multiplies<int>() )
         << endl;
}
