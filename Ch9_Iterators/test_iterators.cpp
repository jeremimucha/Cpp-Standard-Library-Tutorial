// Chapter 9 Iterators -- test code for my implementation of inserters
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <algorithm>
#include "print.hpp"
#include "inserters.hpp"
using namespace std;


int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9};
    vector<int> vec2;

    copy(vec.cbegin(), vec.cend(),
         make_backinserter(vec2));
    PRINT_ELEMENTS(vec2, "vec2: ");

    
    deque<int> dq;
    copy(vec.cbegin(), vec.cend(),
         make_frontinserter(dq));
    PRINT_ELEMENTS(dq,   "dq:   ");


    list<int> lst;
    copy(vec.cbegin(), vec.cend(),
         make_myinserter(lst, lst.begin()));
    PRINT_ELEMENTS(lst,  "lst:  ");
    
    return 0;
}
