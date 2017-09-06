// revers iterators
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
using namespace std;


int main()
{
    vector<int> coll{0,1,2,3,4,5,6,7,8,9};

    vector<int>::iterator pos;
    pos = find(coll.begin(), coll.end(), 3);
    cout << "*pos:     " << *pos
         << "\ndistance: " << distance(coll.begin(), pos);

    vector<int>::reverse_iterator rpos;
    rpos = find(coll.rbegin(), coll.rend(), 3);
    cout << "\n\n*rpos: " << *rpos
         << "\ndistance: " << distance(rpos, coll.rend());
}
