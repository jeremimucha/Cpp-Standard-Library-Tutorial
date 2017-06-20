// sharedptr2.cpp -- Ch5 Utilities -- specifying destruction policies
// necessary if shared or unique ptr are pointing to arrays, or
// when other cleanup needs to be done - e.g. removing a temporary file
#include <iostream>
#include <fstream>
#include <memory>
#include <cstdio>   // for remove()


class FileDeleter
{
private:
    std::string filename;
public:
    FileDeleter(const std::string& fn)
        : filename(fn)
        { }
    void operator()(std::ofstream* fp)
        {
            fp->close();
            std::remove(filename.c_str());
        }
};


int main()
{
    // create and open temporary file:
    std::shared_ptr<std::ofstream> fp(new std::ofstream("tempfile.txt"),
                                      FileDeleter("tempfile.txt"));
}
