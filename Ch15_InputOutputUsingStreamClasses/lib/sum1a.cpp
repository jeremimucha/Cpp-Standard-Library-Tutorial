// Chapter 15 IO
#include <istream>


namespace MyLib
{
double readAndProcessSum( std::istream& strm )
{
    using std::ios;
    double value, sum;

    // save current state of exception flags
    ios::iostate oldExceptions = strm.exceptions();

    // let failbit and badbit throw exceptions
    // - NOTE: failbit is also set at EOF
    strm.exceptions( ios::failbit | ios::badbit );

    try{
        // while stream is OK
        // - read value and add it to sum
        sum = 0;
        while( strm >> value ){
            sum += value;
        }
    }
    catch( ... ){
        // if exception not caused by EOF
        // - restore old state of exception flags
        // - rethrow exception
        if( !strm.eof() ){
            strm.exceptions( oldExceptions );   // restore exception flags
            throw;
        }
    }

    // restore old state of exceptions flags
    strm.exceptions( oldExceptions );
    return sum;
}
}   // MyLib
