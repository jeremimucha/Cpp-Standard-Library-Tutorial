// sharedptr1.cpp -- Ch5 Utilities -- using the shared_ptr class
#include <iostream>
#include <string>
#include <vector>
#include <memory>


int main()
{
    using std::cout; using std::endl;
    using std::string;
    using std::vector;
    using std::shared_ptr;
    using std::make_shared;

    // two shared pointers representing two persons by their name
    // a lambda is passsed as the second argument - this defines a Deleter
    // it is called before the object is destroyed.
    // The deleter is optional.
    shared_ptr<string> pNico(new string("nico"),
                            [](string* p){cout << "delete " << *p << endl;
                                          delete p;});
    // shared_ptr<string> pJutta(new string("jutta"));
    // use make_shared<> to initialize the shared_ptr - safer and faster
    // avoids one allocation
    shared_ptr<string> pJutta{make_shared<string>("jutta")};

    // capitalize person names
    (*pNico)[0] = 'N';
    pJutta->replace(0,1,"J");

    // put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee;
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);

    // print all elements
    for(auto ptr : whoMadeCoffee){
        cout << *ptr << "   ";
    }
    cout << endl;

    // overwrite a name again
    *pNico = "Nicolai";

    // print all elements again
    for(auto ptr : whoMadeCoffee){
        cout << *ptr << "   ";
    }
    cout << endl;

    // get rid of all references to the std::string origianlly pointed to by pNico
    whoMadeCoffee.resize(2);
    pNico = nullptr;

    // print some internal data
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;

}
