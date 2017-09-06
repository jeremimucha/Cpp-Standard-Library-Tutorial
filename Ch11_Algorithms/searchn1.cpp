// Chapter 11 Algorithms -- search search_n
#include "algostuff.hpp"
using namespace std;


int main()
{
    deque<int> coll{1,2,7,7,6,3,9,5,7,7,7,3,6};
    PRINT_ELEMENTS(coll);

    // find three consecutive elements with value 7
    deque<int>::iterator pos;
    pos = search_n(coll.begin(), coll.end(),        // range
                   3,                                // count
                   7);                              // value
    // print result
    if(pos != coll.end()){
        cout << "three consecutive elemnts with vlaue 7 "
             << "start with " << distance(coll.begin(), pos) + 1
             << ". element" << endl;
    }
    else{
        cout << "no three consecutive elements with value 7 found"
             << endl;
    }

    // find four consecutive odd elements
    pos = search_n(coll.begin(), coll.end(),
                   4,
                   0,
                   [](int elem, int value)
                    { return elem%2 == 1; }
                  );

    // print result
    if(pos != coll.end()){
        cout << "first four consecutive odd elements are: ";
        for(int i=0; i<4; ++i, ++pos){
            cout << *pos << ' ';
        }
    }
    else{
        cout << "no four consecutive elements with vlaue >3 found";
    }
    cout << endl;
}
