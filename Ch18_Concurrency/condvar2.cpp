// Chapter 18 Concurrency
#include <condition_variable>
#include <mutex>
#include <future>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>


std::queue<int>         queue;
std::mutex              queueMutex;
std::condition_variable queueCondVar;

std::mutex coutMutex;


void provider( int val )
{   
    { std::lock_guard<std::mutex> l(coutMutex);
        std::cout << "provider [" << std::this_thread::get_id()
                  << "] started" << std::endl;
    }
    // push different values (val til val+5 with timeouts of
    // val milliseconds into the queue)
    for( int i=0; i<6; ++i ){
        { std::lock_guard<std::mutex> lg(queueMutex);
            queue.push(val+i);
        } // release lock
        queueCondVar.notify_one();
        std::this_thread::sleep_for( std::chrono::milliseconds(val) );
    }
}


void consumer( int num )
{
    { std::lock_guard<std::mutex> l(coutMutex);
        std::cout << "consumer [" << std::this_thread::get_id()
                  << "] started" << std::endl;
    }
    // pop values if available (num identifies the consumer)
    while(true){
        int val;
        { std::unique_lock<std::mutex> ul(queueMutex);
            queueCondVar.wait( ul, [](){ return !queue.empty(); } );
            val = queue.front();
            queue.pop();
        } // release lock
        std::cout << "consumer " << num << ": " << val << std::endl;
    }
}


int main()
{
    { std::lock_guard<std::mutex> lk(coutMutex);
        std::cout << "main [" << std::this_thread::get_id() << "]" << std::endl;
    }
    // start three providers for values 100+, 300+, 500+
    std::future<void> p1 = std::async( std::launch::async, provider, 100 );
    std::future<void> p2 = std::async( std::launch::async, provider, 300 );
    std::future<void> p3 = std::async( std::launch::async, provider, 500 );

    // start two consumers printing the values
    auto c1 = std::async( std::launch::async, consumer, 1 );
    auto c2 = std::async( std::launch::async, consumer, 2 );
}
