// Chpater 15 IO
#include <iostream>
#include <fstream>
#include <memory>
using namespace std;


void redirect( ostream& );


int main()
{
    cout << "the first row" << endl;

    redirect( cout );

    cout << "the last row" << endl;
}


void redirect( ostream& strm )
{
    // save output buffer of the stream
    // - use unique pointer with deleter that ensures to restore
    //   the original output buffer at the end of the function.
    auto del = [&]( streambuf* p ){ strm.rdbuf(p); };
    unique_ptr<streambuf,decltype(del)> origBuffer( strm.rdbuf(), del );

    // redirect output into the file redirect.txt
    ofstream file( "redirect.txt" );
    strm.rdbuf( file.rdbuf() );

    file << "one row for the file" << endl;
    strm << "one row for the stream" << endl;
}   // closes file AND its buffer automatically
