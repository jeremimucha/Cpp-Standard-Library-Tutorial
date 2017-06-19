// pair1.cpp -- Ch5 Utilities pair template class example
#include <iostream>
#include <utility>
#include <tuple>


class Foo
{
public:
    Foo(std::tuple<int,float>)
        { std::cout << "Foo::Foo(tuple<int,float>)\n"; }
    template<typename... Args>
    Foo(Args... args)
        { std::cout << "Foo::Foo(args...)\n"; }
};


int main()
{
    // create tuple t:
    std::tuple<int,float> t(1, 2.22);

    // pass teh tuple as a whole to the constructor of Foo:
    std::pair<int,Foo> p1(42, t);

    // pass the **elements** of the tuple to the constructor of Foo:
    std::pair<int,Foo> p2(std::piecewise_construct, std::make_tuple(42), t);
}
