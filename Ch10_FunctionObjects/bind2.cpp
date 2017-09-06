// Chapter 10 Function Objects -- using bind for member functions
#include <functional>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <memory>
using namespace std;
using namespace std::placeholders;


class Person
{
private:
    string name;
public:
    Person(const string& n)
        : name(n)
        { }
    void print() const
        { cout << name << endl; }

    void print2(const string& prefix) const
        { cout << prefix << name << endl; }
};


int main()
{
    vector<Person> coll{Person("Tick"), Person("Trick"), Person("Track") };
    
    // call member function print() for each person
    for_each(coll.begin(), coll.end(),
             bind(&Person::print, _1));
    cout << endl;

    // call member function print2() with additional argument for each person
    for_each(coll.begin(), coll.end(),
             bind(&Person::print2, _1, "Person: "));
    cout << endl;

    // call print2() for temporary Person
    bind(&Person::print2, _1, "This is: ")(Person("nico"));
    cout << endl;

    // call a member function manually
    void (Person::*Person_memfnptr)(const string&)const = &Person::print2;
    Person p("Bar");
    (p.*Person_memfnptr)("Foo");

    Person* p_person = new Person("dynamic");
    (p_person->*Person_memfnptr)("This Person is ");
    delete p_person;

    unique_ptr<Person> u(make_unique<Person>("unique"));
    (u.get()->*Person_memfnptr)("This Person is ");
}