// Chapter 18 Concurrency
#include <future>
#include <mutex>
#include <thread>
#include <iostream>
#include <string>

std::mutex printMutex;  // enable synchronized output with print()

void print( const std::string& s )
{
    std::lock_guard<std::mutex> l(printMutex);
    for( char c : s ){
        std::cout.put(c);
    }
    std::cout << std::endl;
}


int main()
{
    // std::future<void> f1 = std::async( std::launch::async,
    //                                 print, "Hello from a first thread" );
    // std::future<void> f2 = std::async( std::launch::async,
    //                                 print, "Hello from second thread" );
    // OR:
    std::thread t1( print, "Hello from first thread" );
    std::thread t2( print, "Hello from second thread" );

    print( "Hello from the main thread" );
    
    t1.join();
    t2.join();
}
