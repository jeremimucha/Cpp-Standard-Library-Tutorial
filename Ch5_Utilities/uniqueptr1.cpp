// uniqueptr1.cpp -- Ch5 Utilities -- unique_ptr example
#include <iostream>
#include <string>
#include <memory>       // for unique_ptr
#include <dirent.h>     // for opendir(),...
#include <cstring>      // for strerror()
#include <cerrno>       // for errno
using namespace std;


class DirCloser
{
public:
    void operator()(DIR* dp){
        if(closedir(dp) != 0){
            std::cerr << "OOPS: closedir() failed" << std::endl;
        }
        else
            std::cerr << "closedir() succeeded\n";
    }
};


int main()
{
    // open current directory
    unique_ptr<DIR, DirCloser> pDir(opendir("."));

    // process each directory entry:
    struct dirent* dp;
    while( (dp = readdir(pDir.get())) != nullptr ){
        string filename(dp->d_name);
        cout << "process " << filename << endl;
    }
}
