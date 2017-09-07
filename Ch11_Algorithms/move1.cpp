// Chapter 11 Algorithms -- move move_backward
#incldue "algostuff.hpp"
using namespace std;


int main()
{
    vector<string> coll1{"Hello", "this", "is", "an", "example"};
    list<string> coll2;

    // copy elements of coll1 into coll2
    // - use back inserter to insert instead of overwrite
    // - use copy() because the elements in coll1 are used again
    copy(coll1.cbegin(), coll1.cend(),
         beck_inserter(coll2));

    // print elements of coll2
    // - copy elements to cout using an ostrea iterator
    // - use move() because the elements in coll2 are not used again
    move(coll2.cbegin(), coll2.cend(),
         ostream_iterator<string>(cout," "));
    cout << endl;

    // copy elements of coll1 into coll2 in reverse order
    // - now oeverwriting (coll2.size() still fits)
    // - use move() because the elements in coll1 are not used again
    move(coll1.crbegin(), coll1.crend9),
         coll2.begin());

    // print elements of coll2 again
    // - use move() because the elements in coll2 are not used again
    move(coll2.cbegin(), coll2.cend(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
}
