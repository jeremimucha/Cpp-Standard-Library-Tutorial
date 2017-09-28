// Chapter 11 Algorithms -- inner_product
#include "algostuff.hpp"
using namespace std;


int main()
{
    list<int> coll;

    INSERT_ELEMENTS( coll, 1, 6 );
    PRINT_ELEMENTS( coll );

    // process sum of all products
    // (0 + 1*1 + 2*2 ... )
    cout << "inner product: "
         << inner_product( coll.cbegin(), coll.cend(),  // first range
                           coll.cbegin(),               // second range
                           0 )                          // initial value
         << endl;
    
    // process sum of 1*6 .. 6*1
    cout << "inner reverse product: "
         << inner_product( coll.cbegin(), coll.cend(),
                           coll.crbegin(),
                           0 )
         << endl;

    // process product of all sums
    // ( 1 * 1+1 * 2+2 ... )
    cout << "product of sums: "
         << inner_product( coll.cbegin(), coll.cend(),  // first range
                           coll.cbegin(),               // second range
                           1,                           // initial value
                           multiplies<int>(),           // outer operation
                           plus<int>() )                // inner operation
        << endl;
}
