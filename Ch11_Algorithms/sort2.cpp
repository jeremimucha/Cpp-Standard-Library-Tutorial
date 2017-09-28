// Chapter 11 Algorithms -- sort stable_sort
#include "algostuff.hpp"
using namespace std;


bool lessLength( const string& s1, const string& s2 )
{
    return s1.length() < s2.length();
}


int main()
{
    // fill two collections with the same elements
    vector<string> coll1 = { "1xxx", "2x", "3x", "4x", "5xx", "6xxxx",
                             "7xx", "8xxx", "9xx", "10xxx", "11", "12",
                             "13", "14xx", "15", "16", "17" };
    vector<string> coll2(coll1);

    PRINT_ELEMENTS( coll1, "on entry:\n" );

    // sort (according to the length of the string)
    sort( coll1.begin(), coll1.end(), lessLength );
    stable_sort( coll2.begin(), coll2.end(), lessLength );

    PRINT_ELEMENTS( coll1, "\nwith sort():\n " );
    PRINT_ELEMENTS( coll2, "\nwith stable_sort():\n " );
}
