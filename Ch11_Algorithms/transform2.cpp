// Chapter 11 Algorithm
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll1;
    list<int> coll2;

    INSERT_ELEMENTS(coll1, 1, 9);
    PRINT_ELEMENTS(coll1, "coll1:    ");

    // square each element
    transform(coll1.cbegin(), coll1.cend(), // first source range
              coll1.cbegin(),               // second source range
              coll1.begin(),                // destination range
              multiplies<int>());           // operation
    PRINT_ELEMENTS(coll1, "squared:  ");

    // add each element traversed forward with each element traverse backward
    // and insert result into coll2
    transform(coll1.cbegin(), coll1.cend(),     // first source range
              coll1.crbegin(),                  // second source range
              back_inserter(coll2),             // destination range
              plus<int>());                     // operation
    PRINT_ELEMENTS(coll2, "coll2:    ");

    // add each element traversed forward with each element traversed backward
    // and insert result into coll2
    transform(coll1.cbegin(), coll1.cend(),     // first source range
              coll1.crbegin(),                  // second source range
              back_inserter(coll2),             // destination range
              plus<int>());
    PRINT_ELEMENTS(coll2, "coll2:    ");

    // print differences of two corresponding elements
    cout << "diff:    ";
    transform(coll1.cbegin(), coll1.cend(),     // first source range
              coll2.cbegin(),
              ostream_iterator<int>(cout," "),
              minus<int>());
    cout << endl;
}
