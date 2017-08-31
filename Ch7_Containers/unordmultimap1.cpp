// Chapter 7 Containers -- unordered map, bucket interface
#include <unordered_map>
#include <string>
#include <utility>
#include "buckets.hpp"
using namespace std;


int main()
{
    // create and initialize an unordered multimap as dictionary
    std::unordered_multimap<string,string> dict{
            {"day", "Tag"}
           ,{"strange","fremd"}
           ,{"smart","elegant"}
           ,{"trait","Merkmal"}
           ,{"strange","seltsam"}
    };
    printHashTableState(dict);

    // insert some additional values (might cause rehashing)
    dict.insert({ {"smart","raffiniert"}
                , {"smart","klug"}
                , {"clever","raffiniert"}
                });
    printHashTableState(dict);

    // modify maximum load factor (might cause rehashing)
    dict.max_load_factor(0.7);
    printHashTableState(dict);
}
