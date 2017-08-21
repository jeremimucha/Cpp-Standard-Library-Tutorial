// weakptr2.cpp -- Ch5 Utilities -- using the weak_ptr class
#include <iostream>
#include <string>
#include <vector>
#include <memory>


class Person
{
public:
    std::string name;
    std::shared_ptr<Person> mother;
    std::shared_ptr<Person> father;
    std::vector<std::weak_ptr<Person>> kids;    // weak pointer!

    Person(const std::string& n, std::shared_ptr<Person> m=nullptr,
           std::shared_ptr<Person> f=nullptr)
        : name(n), mother(m), father(f)
        { }
    ~Person(){ std::cout << "delete " << name << std::endl; }
};


std::shared_ptr<Person> initFamily(const std::string& name)
{
    std::shared_ptr<Person> mom(new Person(name+"'s mom"));
    std::shared_ptr<Person> dad(new Person(name+"'s dad"));
    std::shared_ptr<Person> kid(new Person(name, mom, dad));
    mom->kids.push_back(kid);
    dad->kids.push_back(kid);
    // at this point kid holds references to mom and dad
    // mom and dad each hold a reference to kid
    return kid;
}


int main()
{
    std::shared_ptr<Person> p = initFamily("nico");

    std::cout << "nico's family exists" << std::endl;
    std::cout << "- nico is shared " << p.use_count() << " times" << '\n'
              << "- name of 1st kid of nico's mom: "
            //   .lock() yields a shared_ptr out of a weak_ptr
              << p->mother->kids[0].lock()->name << std::endl;
    std::cout << "- nico's mom is shared " << p->mother.use_count() << " times" <<'\n'
              << "- nico's dad is shared " << p->father.use_count() << " times" <<'\n';
// 'nico' is refered to by weak_ptrs in mom and dad kids vectors
// weak_ptrs don't prevent the object from being destroyed
// mom and dad are refered to once by the 'nico' Person object
    p = initFamily("jim");
// there are no more references to 'nico' object here, which also heald
// shared_ptrs to mom and dad. The 'nico' object is destroyed, hence
// there are no more references to mom and dad - which are also destroyed.
    std::cout << "jim's family exists" << std::endl;
}
