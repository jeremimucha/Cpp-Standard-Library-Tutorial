// Chapter 18 Concurrency
#include <future>
#include <random>
#include <chrono>
#include <list>
#include <iostream>
#include <exception>
using namespace std;


void task1()
{

    default_random_engine dre(42);
    uniform_int_distribution<int> uid(100, 2000);
    for( int i=0; i< 42; ++i ){
        this_thread::sleep_for( chrono::milliseconds( uid(dre) ) );
        cout.put('.').flush();
    }
    throw runtime_error( "task1 exception" );
}


int main()
{
    cout << "starting 2 tasks" << endl;
    cout << "- task1: process endless loop of memory consumption" << endl;
    cout << "- task2: wait for <return> and then for task1" << endl;

    future<void> f1 = async(task1);
    cin.get();  // read a character (like getchar())
    
    cout << "\nwait for the end of task1: " << endl;
    try{
        f1.get();   // wait for task1() to finish (raises exception if any)
    }
    catch( const exception& e ){
        cerr << "EXCEPTION: " << e.what() << endl;
    }
}
