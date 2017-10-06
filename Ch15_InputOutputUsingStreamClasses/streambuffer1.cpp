// Chapter 15 IO
#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    // stream for hexadecimal standard output
    ostream hexout( cout.rdbuf() );
    hexout.setf( ios_base::hex, ios_base::basefield );
    hexout.setf( ios_base::showbase );

    // switch between decimal and hexadecimal output
    hexout << "hexout: " << 177 << " ";
    cout   << "cout: " << 177 << " ";
    hexout << "hexout: " << -49 << " ";
    cout   << "cout: " << -49 << " ";
    hexout << endl;
}
