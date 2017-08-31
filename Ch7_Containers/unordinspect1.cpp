// Chapter 7 Containers -- unordered container bucket structure inspection
#include <unordered_set>
#include <iostream>
#include "buckets.hpp"


int main()
{
    // create and initialize an unordered set
    std::unordered_set<int> intset{1,2,3,5,7,11,13,17,19};
    printHashTableState(intset);

    // insert some additional values (might cause rehashing)
    intset.insert({-7, 17, 33, 4});
    printHashTableState(intset);
}
