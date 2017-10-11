// Chapter 18 Concurrency
#include <condition_variable>
#include <mutex>
#include <future>
#include <iostream>


bool readyFlag;
std::mutex readyMutex;
std::condition_variable readyCondVar;


void thread1()
{
    std::cout << "thread1(): Thread id: " << std::this_thread::get_id()
              << ", started" << std::endl;
    // do something thread2 needs as preparation
    std::cout << "<return>" << std::endl;
    std::cin.get();

    // signal that thread1 has prepared a condition
    { std::lock_guard<std::mutex> lg(readyMutex);
        readyFlag = true;
    } // release lock
    readyCondVar.notify_one();
}


void thread2()
{
    std::cout << "thread2(): Thread id: " << std::this_thread::get_id()
              << ", started" << std::endl;
    // wait until thread1 is ready (readyFlag is true)
    { std::unique_lock<std::mutex> ul(readyMutex);
        readyCondVar.wait( ul, [](){ return readyFlag; } ); 
    } // release lock

    // do whatever shall happen after thread1 has prepared things
    std::cout << "thread2(): Thread id: "
              << std::this_thread::get_id() << ", done" << std::endl;
}



int main()
{
    std::cout << "main: Thread id: " << std::this_thread::get_id()
              << ", started" << std::endl;
    auto f1 = std::async( std::launch::async, thread1 );
    std::future<void> f2 = std::async( std::launch::async, thread2 );
}
