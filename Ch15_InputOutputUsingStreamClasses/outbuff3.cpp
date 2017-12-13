#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "outbuf3.hpp"


int main()
{
    FILE* file = std::fopen( "outbuf3_test.txt", "w" );
    if( !file ){
        std::cerr << "Failed to open file\n" << std::endl;
        exit(EXIT_FAILURE);
    }
    outbufstream ofs(file);
    ofs << "Here's some output for the file.\n" << std::endl;
    std::fclose(file);
}
