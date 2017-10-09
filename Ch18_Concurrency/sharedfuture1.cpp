// Chapter 18 Concurrency
#include <future>
#include <thread>
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;


int queryNumber()
{
    // read number
    cout << "read number: ";
    int num;
    cin >> num;

    // throw exception if none
    if(!cin){
        throw runtime_error( "no number read" );
    }

    return num;
}

void doSomething( char c, shared_future<int> f )
{
    int waitfor;
    switch(c){
        case '.': waitfor = 50; break;
        case '+': waitfor = 100; break;
        case '*': waitfor = 200; break;
        default: waitfor = 500; break;
    }
    try{
        // wait for number of characters to print
        int num = f.get();  // get result of queryNumber()
        for( int i=0; i<num; ++i ){
            this_thread::sleep_for( chrono::milliseconds(waitfor) );
            cout.put(c).flush();
        }
    }
    catch( const exception& e ){
        cerr << "EXCEPTION: in thread " << this_thread::get_id()
             << ": " << e.what() << endl;
    }
}


int main()
{
    try{
        // start one thread to query a number
        shared_future<int> f = async(queryNumber);

        // start three threads each processing this number in a loop
        future<void> f1 = async( launch::async, doSomething, '.', f );
        future<void> f2 = async( launch::async, doSomething, '+', f );
        future<void> f3 = async( launch::async, doSomething, '*', f );

        // wait for all loops to be finished
        std::cout << "\nbefore future1 is done" << std::endl;
        f1.get();
        // will execute after f1 returns
        std::cout << "\nfuture 1 is done" << std::endl;
        f2.get();
        f3.get();
    }
    catch( const exception& e ){
        cout << "\nEXCEPTION: " << e.what() << endl;
    }
    cout << "\ndone" << endl;
}
