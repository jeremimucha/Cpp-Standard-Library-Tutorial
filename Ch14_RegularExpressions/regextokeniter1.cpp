// Chapter 14 Regular Expressions
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

    regex reg("<(.*)>(.*)</(\\1)>");

    // iterate over all matches (using a regex_token_iterator):
    sregex_token_iterator pos( data.cbegin(), data.cend(),  // sequence
                               reg,                         // token separator
                               {0,2} );  // 0: full match, 2: second substring
                    
    sregex_token_iterator end;
    for( ; pos!=end; ++pos ){
        cout << "match:  " << pos->str() << endl;
    }
    cout << endl;

    string names = "nico, jim, helmut, paul, tim, john paul, rita";
    regex sep("[ \t\n]*[,;.] [ \t\n]*");    //separated by ,; or . and spaces
    sregex_token_iterator p(names.cbegin(), names.cend(),   // sequence
                            sep,                            // separator
                            -1 );       // -1: values between separators
                
    sregex_token_iterator e;
    for( ; p!=e; ++p ){
        cout << "name:  " << *p << endl;
    }
}
