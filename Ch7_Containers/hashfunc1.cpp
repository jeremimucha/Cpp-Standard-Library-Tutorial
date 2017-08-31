// Chapter 7 Containers - hash function, equivalence criterion
#include <unordered_set>
#include <string>
#include <iostream>
#include "hashval.hpp"
#include "print.hpp"
using namespace std;


class Customer
{
private:
    string fname;
    string lname;
    long no;
public:
    Customer(const string& fn, const string& ln, long n)
        : fname(fn), lname(ln), no(n)
        { }
    
    friend ostream& operator<<(ostream& os, const Customer& c)
        { return os << "[" << c.fname << "," << c.lname << ","
                    << c.no << "]"; }

    friend class CustomerHash;
    friend class CustomerEqual;
};


class CustomerHash
{
public:
    std::size_t operator()(const Customer& c) const
        {
            return hash_val(c.fname, c.lname, c.no);
        }
};

class CustomerEqual
{
public:
    bool operator()(const Customer& c1, const Customer& c2) const
        {
            return c1.no == c2.no;
        }
};


int main()
{
    // unordered set with own hash function and equivalence criterion
    unordered_set<Customer, CustomerHash, CustomerEqual> custset;

    custset.insert(Customer("nico", "jousttis", 42));
    PRINT_ELEMENTS(custset);
}
