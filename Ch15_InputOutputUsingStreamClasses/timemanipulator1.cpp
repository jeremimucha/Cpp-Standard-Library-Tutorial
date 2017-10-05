// Chapter 15 IO
#include <iostream>
#include <iomanip>
#include <chrono>
#include <cstdlib>
using namespace std;


int main()
{
    // process and print current date and time:
    auto now = chrono::system_clock::now();
    time_t t = chrono::system_clock::to_time_t(now);
    tm* nowTM = localtime(&t);
    cout << put_time(nowTM, "date: %x\ntime: %X\n") << endl;

    // read date:
    tm* date;
    cout << "new date: ";
    cin >> get_time( date, "%x" ); // read date
    if( !cin ){
        cerr << "invalid format read" << endl;
    }
}
