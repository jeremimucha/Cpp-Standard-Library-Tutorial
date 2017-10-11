// Chapter 18 Concurrency
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <random>
#include <exception>
#include <utility>
using namespace std;


double do_computation( int x, int y )
{
    default_random_engine dre( x*y );
    uniform_int_distribution<int> uid(100,1000);
    for( int i=0; i<10; ++i ){
        this_thread::sleep_for( chrono::milliseconds( uid(dre) ) );
        cout << "running do_computation(" << x << "," << y << ")" << endl;
    }
    return x * y + (x/y);
}


int main()
try{
    packaged_task<double(int,int)> task1( do_computation );  // create a task
    
    auto lamb = [](int x, int y)
                { 
                    default_random_engine dre(x*y);
                    uniform_int_distribution<int> uid(300, 500);
                    for( int i=0; i<10; ++i ){
                        this_thread::sleep_for( chrono::milliseconds( uid(dre) ) );
                        cout << "running lam(" << x << "," << y << ")" << endl;
                    }
                    return x > y;
                };
    packaged_task<bool(int,int)> task2( lamb );
    // packaged_task<bool(int,int)> task2( [](int x,int y)
    //     {
    //         default_random_engine dre(x*y);
    //         uniform_int_distribution<int> uid(300, 500);
    //         for( int i=0; i<10; ++i ){
    //             this_thread::sleep_for( chrono::milliseconds( uid(dre) ) );
    //             cout << "running lam(" << x << "," << y << ")" << endl;
    //         }
    //         return x > y;
    //     });

    future<double> f1 = task1.get_future();
    future<bool> f2 = task2.get_future();

    thread t1( std::move(task1), 9, 11 );
    thread t2( std::move(task2), 9, 42 );

    t1.join();
    t2.join();

    cout << endl;
    cout << "task1: " << f1.get() << endl;
    cout << "task2: " << boolalpha << f2.get() << endl;

}
catch( const exception& e ){
    cerr << "EXCEPTION: " << e.what() << endl;
}