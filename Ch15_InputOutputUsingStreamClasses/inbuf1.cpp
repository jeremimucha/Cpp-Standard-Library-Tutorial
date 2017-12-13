#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include "inbuf1.hpp"


int main()
{
    FILE* file = fopen( "inbuf1.cpp", "r" );
    if( !file ){
        std::cerr << "Failed to open the file" << std::endl;
        exit(EXIT_FAILURE);
    }

    inbufstream is(file);
    for( char ch, i=0; i < 20; ++i ){
        is.get(ch);
        std::cout << ch;
        
        // unget two characters at some point
        if( i == 9 ){
            is.unget(); is.unget();
        }
    }

    // read using the input operator
    for( std::string s; is >> s; )
        std::cout << s;

    //  flush
    std::cout << std::endl;
}
