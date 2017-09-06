// Chapter 5 Utilities -- unique_ptr usage example
#include <iostream>
#include <string>
#include <memory>
#include <cstdlib>
using namespace std;


class FileCloser
{
public:
    void operator()(FILE* fp){
        if(fp){
            std::cerr << "Closing file " << reinterpret_cast<const void*>(fp)
                      << std::endl;
            // std::fflush(fp);
            std::fclose(fp);
        }
        else
            std::cerr << "File " << reinterpret_cast<const void*>(fp)
                      << " is a nullptr" << std::endl;
    }
};


int main(int argc, char* argv[])
{
    {
    if(argc != 2){
        std::cerr << "Usage: " << argv[0] << " inputfile\n";
        exit(EXIT_FAILURE);
    }

    unique_ptr<FILE, FileCloser> fp( fopen(argv[1], "r"), FileCloser());
    if(fp == nullptr){
        std::cerr << "Failed to open the file " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }

    // use the file somehow
    // file will be closed when fp leaves scope.
    }
}
