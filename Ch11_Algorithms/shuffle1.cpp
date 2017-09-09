// Chapter 11 Algorithms -- shuffle random_shuffle
#include "algostuff.hpp"
#include <cstdlib>
#include <random>
using namespace std;


int main()
{
    vector<int> coll;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll:      ");

    // shuffle all elements randomly
    random_shuffle(coll.begin(), coll.end());

    PRINT_ELEMENTS(coll, "shuffled:  ");

    // sort them again
    sort(coll.begin(), coll.end());
    PRINT_ELEMENTS(coll, "sorted:    ");

    // shuffle elements with default engine
    default_random_engine dre;
    shuffle(coll.begin(), coll.end(),
            dre);

    PRINT_ELEMENTS(coll, "shuffled:  ");
}
