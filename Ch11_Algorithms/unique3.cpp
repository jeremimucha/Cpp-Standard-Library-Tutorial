// Chapter 11 Algorithms -- unique_copy
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;


bool bothSpaces(char elem1, char elem2)
{
    return elem1 == ' ' && elem2 == ' ';
}

int main()
{
    // don't skip leading whitespaces by default
    cin.unsetf(ios::skipws);

    // copy standard input to standard output
    // - while compressing spaces
    unique_copy(istream_iterator<char>(cin),    // beginning of source: cin
                istream_iterator<char>(),       // end of source: EOF
                ostream_iterator<char>(cout),   // destination: cout
                bothSpaces);                    // duplicate criterion
}
