// Chapter 14 Regular expressions
#include <string>
#include <regex>
#include <iostream>
#include <algorithm>
using namespace std;


int main()
{
    string data = "<person>\n"
                  "<first>Nico</first>\n"
                  "<last>Josuttis</last>\n"
                  "</person>\n";

    regex reg( "<(.*)>(.*)</(\\1)>" );

    // iterate over all matches (using a regex_iterator):
    sregex_iterator pos( data.cbegin(), data.cend(), reg );
    sregex_iterator end;
    for( ; pos != end; ++pos ){
        cout << "match :  " << pos->str( ) << endl;
        cout << "   tag:  " << pos->str(1) << endl;
        cout << " value:  " << pos->str(2) << endl;
    }

    // use a regex_iterator to process each matched substring as element in
    // an algorithm
    sregex_iterator beg( data.cbegin(), data.cend(), reg );
    for_each( beg, end, [](const smatch& m)
                        {
                            cout << "match :  " << m.str( ) << endl;
                            cout << "   tag:  " << m.str(1) << endl;
                            cout << " value:  " << m.str(2) << endl;
                        });
}
