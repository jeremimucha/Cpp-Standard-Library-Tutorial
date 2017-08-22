// vector1.cpp -- Chapter 7
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;


int main()
{
    // create empty vector for string
    vector<string> sentence;

    // reserve memory for five elements to avoid reeallocation
    sentence.reserve(5);

    // append some elements
    sentence.push_back("Hello, ");
    sentence.insert(sentence.end(), {"how", "are", "you", "?"});

    // print elements separeated with spaces
    copy(sentence.cbegin(), sentence.cend(),
            ostream_iterator<string>(cout, " "));
    cout << endl;

    // print "technical data"
    cout << "  max_size(): " << sentence.max_size() << endl;
    cout << "  size():     " << sentence.size() << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;

    // swap second and fourth element
    swap(sentence[1], sentence[3]);

    // insert element "always" before element "?"
    sentence.insert(find(sentence.begin(), sentence.end(), "?"),
                    "always");

    // assign "!", to the last element
    sentence.back() = "!";

    // print elements separated with spaces
    copy(sentence.cbegin(), sentence.cend(),
         ostream_iterator<string>(cout, " "));
    cout << endl;
    
    // print "technical data" again
    cout << "  size():     " << sentence.size() << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;

    // delete last two elements
    sentence.pop_back();
    sentence.pop_back();
    // shrink capacity
    sentence.shrink_to_fit();

    // print some "technical data" again
    cout << "  size():     " << sentence.size() << endl;
    cout << "  capacity(): " << sentence.capacity() << endl;
}
