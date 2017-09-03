// Chapter 9 Iterators -- front inserter
#include <list>
#include <algorithm>
#include <iterator>
#include "print.hpp"
using namespace std;


int main()
{
    list<int> coll;

    // create front inserter for coll
    // - inconvenient way
    front_insert_iterator<list<int>> iter(coll);

    // insert elements with the usual iterator interface
    *iter = 1;  // operator* is a no-op that returns *this
                // operator= calls coll.push_front(1);
    ++iter;     // operator++ is a no-op
    *iter = 2;
    iter++;     // operator++(int) is a no-op
    *iter = 3;

    PRINT_ELEMENTS(coll);

    // create front inserter and insert elements
    // - convenient way
    front_inserter(coll) = 44;
    front_inserter(coll) = 55;
    PRINT_ELEMENTS(coll);

    // use front inserter to insert all elements again
    copy(coll.begin(), coll.end(),  // source
         front_inserter(coll));     // destination

    PRINT_ELEMENTS(coll);
}
