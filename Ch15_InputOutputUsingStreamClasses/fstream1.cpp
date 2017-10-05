// Chapter 15 IO
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;


// forward declarations
void writeCharsetToFile( const string& filename );
void outputFile( const string& filename );


int main()
{
    writeCharsetToFile("charset.out");
    outputFile("charset.out");
}


void writeCharsetToFile( const string& filename )
{
    // open output file
    ofstream file( filename );

    // file opened?
    if( !file.is_open() ){
        // NO, abort program
        cerr << "can't open output file \"" << filename << "\""
             << endl;
        exit(EXIT_FAILURE);
    }

    // write character set
    for(int i=32; i<256; ++i){
        file << "value: " << setw(3) << i << "  "
             << "char: " << static_cast<char>(i) << endl;
    }
}   // flushes (?) and closes the file automatically

void outputFile( const string& filename )
{
    // open input file
    ifstream file( filename );

    // file opened?
    if( !file.is_open() ){
        // NO, abort program
        cerr << "can't open input file \"" << filename << "\""
             << endl;
        exit(EXIT_FAILURE);
    }

    // copy file contents to cout
    for( char c; file.get(c); ){
        cout.put(c);
    }
} // closes file automatically
