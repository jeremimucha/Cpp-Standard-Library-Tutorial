// Chapter 15 IO
/* User-defined manipulators */
#ifndef IGNORE_HPP_
#define IGNORE_HPP_

#include <istream>
#include <limits>

template<typename charT, typename traits>
inline std::basic_istream<charT, traits>&
ignoreLine( std::basic_istream<charT,traits>& strm )
{
    // skip until EOF
    strm.ignore( std::numeric_limits<std::streamsize>::max()
               , strm.widen('\n') );

    // return stream for concatenation
    return strm;
}

#endif /* IGNORE_HPP_ */
