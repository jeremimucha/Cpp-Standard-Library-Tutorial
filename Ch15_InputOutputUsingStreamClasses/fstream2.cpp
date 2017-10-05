// Chapter 15 IO
#include <iostream>
#include <fstream>
#include <string>


int main()
{
    // write string to a temporarily created file stream
    std::string s("hello");
    std::ofstream("fstream2.tmp") << s << std::endl;

    // write C-string to a temporarily created file stream
    // - NOTE: wrote a pointer value before C++11
    std::ofstream("fstream2.tmp", std::ios_base::app) << "world" << std::endl;
}
