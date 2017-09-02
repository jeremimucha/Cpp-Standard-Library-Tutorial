// Chapter 7 Containers -- using a vector to collect input, sort it and make unique
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;


int main()
{
    // create a string vector
    // - initialized by all words from standard input
    vector<string> coll((istream_iterator<string>(cin)),
                         istream_iterator<string>());

    // sort all elements
    sort(coll.begin(), coll.end());

    // print al elements ignoring subsequent duplicated
    unique_copy(coll.cbegin(), coll.cend(),
                ostream_iterator<string>(cout, "\n"));
}
