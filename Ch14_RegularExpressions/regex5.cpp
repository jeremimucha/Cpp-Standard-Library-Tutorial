// Chapter 14 Regular expressions
#include <regex>
#include <iostream>
#include "regexexception.hpp"
using namespace std;


int main()
{
    try{
        // initialize regular expression with invalid syntax:
        regex pat( "\\\\.*index\\{([^}]*)\\}",
                   regex_constants::grep|regex_constants::icase );
    }
    catch( const regex_error& e ){
        cerr << "regex_error: \n"
             << " what(): " << e.what() << "\n"
             << " code(): " << regexCode(e.code()) << endl;
    }
}