// weakptr1.cpp -- Ch5 Utilities -- why shared_ptrs don't work for circular
// references
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
    std::vector<std::shared_ptr<Person>> kids;

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
              << p->mother->kids[0]->name << std::endl;
    std::cout << "- nico's mom is shared " << p->mother.use_count() << " times" <<'\n'
              << "- nico's dad is shared " << p->father.use_count() << " times" <<'\n';
// 'nico' is shared 3 times at this point (the 'p' ptr and pointers in mom's
// and dad's kids vectors
// mom and dad are refered to once by the 'nico' Person object
    std::shared_ptr<Person> sp(p->mother);
    p = initFamily("jim");
    std::cout << "afte assigning p = initFamily(\"jim\")\n";
    std::cout << "- nico is shared " << sp->kids[0].use_count() << " times" << '\n';
    std::cout << "- nico's mom is shared " << sp.use_count() << " times" <<'\n'
              << "- nico's dad is shared " << sp->kids[0]->father.use_count() << " times" <<'\n';
    sp = nullptr;
// here 'nico' is still shared 2 times - hence it isn't released
// it also still holds references to mom and dad
    std::cout << "jim's family exists" << std::endl;
}
