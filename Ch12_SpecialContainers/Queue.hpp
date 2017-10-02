// Chapter 12 Special Containers -- safer more convenient Queue implementation
#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <deque>
#include <exception>
#include <utility>


template<typename T>
class Queue
{
protected:
    std::deque<T> c;

public:
/* typedefs */
    typedef typename std::deque<T>::size_type   size_type;
    typedef T                                   value_type;
    typedef T*                                  pointer;
    typedef const T*                            const_pointer;
    typedef T&                                  reference;
    typedef const T&                            const_reference;

/* exceptions */
    class ReadEmptyQueue : public std::exception
    {
    public:
        virtual const char* what() const throw()
        { return "Read empty queue"; }
    };

/* member functions */
    size_type size() const
        { return c.size(); }

    bool empty() const
        { return c.empty(); }

    void push( const T& value )
        { c.push_back(value); }

    void push( T&& value )
        { c.push_back( std::move(value) ); }

    template<typename... Args>
    void emplace( Args&&... args )
        { c.emplace_back( std::forward<Args>(args)... ); }

    T pop()
        {
            if( c.empty() ){
                throw ReadEmptyQueue();
            }
            T elem(c.front());
            c.pop_front();
            return elem;
        }
    
    T& front()
        {
            if( c.empty() ){
                throw ReadEmptyQueue();
            }
            return c.front();
        }
};


#endif /* QUEUE_HPP_ */
