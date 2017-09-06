// Chapter 11 Algorithms -- count count_if
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll;
    int num;
    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    // count elements with value 4
    num = count(coll.cbegin(), coll.cend(),     // range
                4);                             // value
    cout << "number of elements equal to 4:      " << num << endl;
    // count elements with even value
    num = count_if(coll.cbegin(), coll.cend(),  // range
                   [](int elem){ return elem%2 == 0;}
                  );
    cout << "number of elements with even value: " << num << endl;
    // count elements that are greater than vlaue 4
    num = count_if(coll.cbegin(), coll.cend(),  // range
                   [](int elem){ return elem>4; }
                  );
    cout << "number of elements greater than 4:  " << num << endl;
}
