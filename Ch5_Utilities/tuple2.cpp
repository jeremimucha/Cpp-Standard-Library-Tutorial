// tuple2.cpp -- Ch5 Utilities -- using the printtuple.hpp header
// printing tuples to stdout
#include "printtuple.hpp"
#include <tuple>
#include <iostream>
#include <string>


int main()
{
    std::tuple<int,float,std::string> t(77, 1.1, "more light");
    std::cout << "io: " << t << std::endl;
}
