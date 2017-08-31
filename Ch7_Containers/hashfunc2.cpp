// Chapter 7 Containers - hash equivalence
#include <string>
#include <iostream>
#include <unordered_set>
#include <functional>
#include "hashval.hpp"
#include "print.hpp"
using namespace std;
using std::placeholders::_1;
using std::placeholders::_2;

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
    string firstname() const
        { return fname; }
    string lastname() const
        { return lname; }
    long number() const
        { return no; }
    bool cmp_by_number(const Customer& other) const
        { return no == other.no; }
    
    friend ostream& operator<<(ostream& os, const Customer& c)
    {
        return os << "[" << c.fname << "," << c.lname << ","
                  << c.no << "]";
    }
};


int main()
{
    // lambda for user-defined hash function
    auto hash = [](const Customer& c)
                { return hash_val(c.firstname(), c.lastname(), c.number()); };

    // lambda for user-defined equality criterion
    auto eq = [](const Customer& c1, Customer& c2)
              { return c1.number() == c2.number(); };

    // create unordered set with user-defined behavior
    unordered_set<Customer,
                  decltype(hash), decltype(eq)> custset(10, hash, eq);

    unordered_set<Customer, decltype(hash),
                  function<bool(const Customer&,const Customer&)>>
                    custset2(10, hash, bind(&Customer::cmp_by_number, _1, _2));

    custset2.insert(Customer("nuco", "jousttis", 42));

    custset.insert(Customer("nico", "jousttis", 42));

    PRINT_ELEMENTS(custset);
    PRINT_ELEMENTS(custset2);
}
