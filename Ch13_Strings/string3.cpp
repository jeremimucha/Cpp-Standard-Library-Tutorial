// Chapter 13 Strings
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <locale>
using namespace std;


int main()
{
    string input;

    // don't skip leading whitespaces
    cin.unsetf( ios::skipws );

    // read all characters while compressing whitespaces
    const locale& loc( cin.getloc() );  // locale
    unique_copy( istream_iterator<char>(cin),   // beginning of source
                 istream_iterator<char>(),      // end of source
                 back_inserter(input),          // destination
                 [=](char c1, char c2)
                 { return isspace(c1,loc) && isspace(c2, loc); } );

    // process input
    // - here: write it to the standard output
    cout << input;
}
