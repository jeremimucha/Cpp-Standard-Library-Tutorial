// tuple1.cpp -- Ch5 Utilities -- using the tuple template class
#include <iostream>
#include <tuple>
#include <complex>
#include <string>


int main()
{
    // create a four-element tuple
    // - elements are iintialized with default value (0 for fundamental types)
    std::tuple<std::string,int,int,std::complex<double>> t;

    // create and initialize a tuple explicitly
    std::tuple<int,float,std::string> t1(41, 6.3, "nico");

    // 'iterate' over elements:
    using std::cout;
    using std::get;
    cout << get<0>(t1) << " ";
    cout << get<1>(t1) << " ";
    cout << get<2>(t1) << " ";
    cout << std::endl;

    // create tuple with make_tuple()
    // - auto declares t2 with type  of right-hand side
    // - thus, type of t2 is tuple
    auto t2 = std::make_tuple(22, 44, "nico");

    // assign second value in t2 to t1
    get<1>(t1) = get<1>(t2);

    // comparison and assignment
    // - including type conversion from tuple<int,int,const char*>
    // to tuple<int,float,string>
    if(t1 < t2){    // compares value for value
        t1 = t2;    // OK, a ssigns value for value
    }
}
