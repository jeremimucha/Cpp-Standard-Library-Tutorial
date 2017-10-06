// Chapter 15 IO
#include <iostream>


template<typename charT, typename traits>
inline
std::basic_istream<charT,traits>&
operator>>( std::basic_istream<charT,traits>& strm, Fraction& f )
{
    int n, d;

    // read value of numerator
    strm >> n;

    // if available
    // - read '/' and value of denominator
    if(strm.peek() == '/'){
        strm.ignore();
        strm >> d;
    }
    else{
        d = 1;
    }

    // if denominator is zero
    // - set failbit as I/O format error
    if( d == 0 ){
        strm.setstate(std::ios_base::failbit);
        return strm;
    }

    // if everything is fine so far
    // - change the value of the fraction
    if( strm ){
        f = Fraction(n,d);
    }

    return strm;
}