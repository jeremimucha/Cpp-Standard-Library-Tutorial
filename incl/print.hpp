// print.hpp -- a function template to print all elements of a collection
// with an optional leading string
#ifndef PRINT_H_
#define PRINT_H_

#include <iostream>
#include <string>

/* PRINT_ELEMENTS()
 * prints optional string optstr followed by
 * all elements of the collection coll
 * in one line, separated by spaces
 */
template<typename T>
inline void PRINT_ELEMENTS(const T& coll, const std::string& optstr="", bool print_newline=true)
{
    std::cout << optstr;
    for(typename T::const_iterator it = coll.cbegin(); it != coll.cend(); /**/){
        std::cout << *it++ << ' ';
    }
    if(print_newline)
        std::cout << std::endl;
}


#endif /* PRINT_H_ */
