// Chapter 15 IO
#include <iostream>
#include <fstream>


void printFileTwice( const char* filename )
{
    // open file
    std::ifstream file(filename);

    // print contents the first time
    std::cout << file.rdbuf();

    // seek to the beginning
    file.seekg(std::ios_base::beg);

    // print contents the second time
    std::cout << file.rdbuf();
}


int main( int argc, char* argv[] )
{
    // print all files passed as a command-line argument twice
    for( int i=1; i<argc; ++i ){
        printFileTwice( argv[i] );
    }
}
