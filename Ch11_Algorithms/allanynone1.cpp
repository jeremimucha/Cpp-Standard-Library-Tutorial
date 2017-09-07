// Chapter 11 Algorithms -- all_of any_of none_of
#include "algostuff.hpp"
using namespace std;


int main()
{
    vector<int> coll;
    vector<int>::iterator pos;

    INSERT_ELEMENTS(coll, 1, 9);
    PRINT_ELEMENTS(coll, "coll: ");

    // define an object for the predicate(using a lambda)
    auto isEven = [](int elem){ return elem%2 == 0; };

    // print whether all, any or none of the elements are/is even
    cout << boolalpha << "all even?:  "
         << all_of(coll.cbegin(), coll.cend(), isEven) << endl;
    cout << "any even?:  "
         << any_of(coll.cbegin(), coll.cend(), isEven) << endl;
    cout << "none even?: "
         << none_of(coll.cbegin(), coll.cend(), isEven) << endl;

}
