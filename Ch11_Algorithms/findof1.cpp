// Chapter 11 Algorithms -- find_first_of
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll;
    list<int> searchcoll;


    INSERT_ELEMENTS(coll, 1, 11);
    INSERT_ELEMENTS(searchcoll, 3, 5);

    PRINT_ELEMENTS(coll,       "coll:       ");
    PRINT_ELEMENTS(searchcoll, "searchcoll: ");

    // search first occurrence of an element of earchcoll in coll
    vector<int>::iterator pos;
    pos = find_first_of(coll.begin(), coll.end(),   // range
                        searchcoll.begin(),         // beginning of search set)
                        searchcoll.end()            // end of search set
                       );
    cout << "first element of searchcoll in coll is element "
         << distance(coll.begin(),pos) + 1
         << endl;

    // search last occurrence of an element of searchcoll in coll
    vector<int>::reverse_iterator rpos;
    rpos = find_first_of(coll.rbegin(), coll.rend(),    // range
                         searchcoll.begin(),
                         searchcoll.end()
                        );
    cout << "last element of searchcoll in coll is element "
         << distance(coll.begin(), rpos.base())
         << endl;
}
