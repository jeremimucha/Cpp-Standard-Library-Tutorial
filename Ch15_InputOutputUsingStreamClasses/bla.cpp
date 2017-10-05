#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <iterator>
using std::cin;
using std::cout;
using std::endl;


namespace std
{
    std::ostream& operator<<( std::ostream& os
                            , const std::pair<char, std::size_t>& p )
    {
        return os << p.first << ": " << p.second;
    }
}


int main()
{
    // typedef std::unordered_map<char,std::size_t> Charmap;
    typedef std::map<char,std::size_t> Charmap;

    Charmap azmap;
    for(char c='a'; c!='z'; ++c){
        azmap.insert(std::make_pair(c,0));
    }

    for(char a; cin>>a;/**/){
        Charmap::iterator it = azmap.find(::tolower(a));
        if( it != azmap.end() ){
            ++it->second;
        }
    }

    std::copy_if(azmap.cbegin(), azmap.cend(),
              std::ostream_iterator<std::pair<char,std::size_t>>(cout,"\n"),
              [](const std::pair<char,std::size_t>& p)
              { return p.second != 0; });
}
