// Chapter 15 IO
/* Using the user-defined streambuffer */
#include <iostream>
#include "outbuf1.hpp"


int main()
{
    outbuf ob;
    std::ostream out( &ob ); // initialize output stream with that output buffer

    out << "31 hexadecimal: " << std::hex << 31 << std::endl;   
}
