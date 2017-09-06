// Chapter 10 Function Objects
// Using the fopow function object defined in fopow.hpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include "fopow.hpp"
using namespace std;
using namespace std::placeholders;


int main()
{
    vector<int> coll{1,2,3,4,5,6,7,8,9};

    // print 3 raised to the power of all elements
    transform(coll.begin(), coll.end(),             // source
              ostream_iterator<float>(cout," "),   // dest
              bind(fopow<float,int>(),3,_1));       // operation
    cout << endl;

    // print all elements raised to the power of 3
    transform(coll.begin(), coll.end(),             // source
              ostream_iterator<float>(cout," "),    // dest
              bind(fopow<float,int>(),_1,3));       // op
    cout << endl;
}
