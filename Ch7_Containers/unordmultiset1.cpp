// Chapter 7 Containers - unordered_set, unordered_multiset
#include <unordered_set>
#include <print.hpp>
using namespace std;


int main()
{
    // create and initialize, expand, and print unordered multiset
    unordered_multiset<int> coll{1,2,3,5,7,11,13,17,19,77};
    coll.insert({-7,17,33,-11,17,19,1,13});
    PRINT_ELEMENTS(coll);

    // remove **all** elements with specific value
    coll.erase(17);

    // remove **one** of the elements with specific value
    auto pos = coll.find(13);
    if(pos != coll.end()){
        coll.erase(pos);
    }
    PRINT_ELEMENTS(coll);
}
