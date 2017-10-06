// Chapter 15 IO
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    // open file "example.dat" for reading and writing
    filebuf buffer;
    ostream output( &buffer );
    istream input( &buffer );
    buffer.open( "example.dat", ios::in | ios::out | ios::trunc );

    for( int i=1; i<=4; ++i ){
        // write one line
        output << i << ". line" << endl;

        // print all file contents
        input.seekg( ios_base::beg );  // seek to the beginning
        for( char c; input.get(c); ){
            cout.put(c);
        }
        cout << endl;
        input.clear();  // clear eofbit and failbit
    }
}
