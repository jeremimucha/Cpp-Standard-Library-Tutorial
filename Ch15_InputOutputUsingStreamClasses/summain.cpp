#include <iostream>
#include <exception>
#include <cstdlib>


namespace MyLib
{
    double readAndProcessSum_(std::istream&);
}


int main()
{
    using namespace std;
    double sum;

    try{
        sum = MyLib::readAndProcessSum_(cin);
    }
    catch(const ios::failure& error){
        cerr << "I/O exception: " << error.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch(const exception& error){
        cerr << "standard exception: " << error.what() << endl;
        exit(EXIT_FAILURE);
    }
    catch(...){
        cerr << "unknown exception" << endl;
        exit(EXIT_FAILURE);
    }

    // print sum
    cout << "sum: " << sum << endl;
}
