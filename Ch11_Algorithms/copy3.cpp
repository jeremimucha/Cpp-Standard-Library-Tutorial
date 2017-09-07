// Chapter 11 Algorithms -- copy
#include "algostuff.hpp"
using namespace std;


int main()
{
    copy(istream_iterator<string>(cin),
         istream_iterator<string>(),
         ostream_iterator<string>(cout,"\n"));
}
