// Chapter 14 Regular expressions
#include <string>
#include <regex>
#include <iostream>
#include <iterator>
using namespace std;


int main()
{
    string data = "<person>\n"
                  "<first>Nico</first>\n"
                  "<last>Josuttis</last>\n"
                  "</person>\n";
    regex reg( "<(.*)>(.*)</(\\1)>" );

    // print data with replacement for matched patterns
    cout << regex_replace (data,                    // data
                           reg,                     // regular expression
                           "<$1 value=\"$2\"/>" )   // replacement
         << endl;
    
    cout << regex_replace(data,
                          reg,
                          "<\\1 value=\"\\2\"/>",
                          regex_constants::format_sed)  // format flag
         << endl;

    // use iterator interface, and
    // - format_no_copy:    don't copy characters that don't match
    // - format_first_only: replace only the first match found
    string res2;
    regex_replace( back_inserter(res2),             // destination
                   data.begin(), data.end(),        // source range
                   reg,                             // regular expression
                   "<$1 value=\"$2\"/>",            // replacement
                   regex_constants::format_no_copy  // format flags
                   | regex_constants::format_first_only );
    cout << res2 << endl;
}
