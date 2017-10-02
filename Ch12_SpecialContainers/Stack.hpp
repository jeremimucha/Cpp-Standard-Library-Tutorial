// Chapter 12 Special Containers -- Stack implementation
/* Stack
 * Safer and more convenient stack class
 */
#ifndef STACK_HPP_
#define STACK_HPP_

#include <deque>
#include <exception>
#include <utility>


template<typename T>
class Stack
{
protected:
    std::deque<T> c;    // container for the elements

public:
/* typedefs */
    typedef typename std::deque<T>::size_type       size_type;
    typedef T                                       value_type;
    typedef T*                                      pointer;
    typedef const T*                                const_pointer;
    typedef T&                                      reference;
    typedef const T&                                const_reference;
/* exception class for pop() and top() with empty stack */
    class ReadEmptyStack : public std::exception
    {
    public:
        virtual const char* what() const throw(){
            return "read empty stack";
        }
    };

    // number of elements
    size_type size() const
        { return c.size(); }

    // is stack empty?
    bool empty() const
        { return c.empty(); }

    // push element into the stack
    void push(const T& elem)
        { c.push_back(elem); }

    void push( T&& elem )
        { c.push_back( std::move(elem) ); }

    template<typename... Args>
    void emplace( Args&&... args )
        { c.emplace_back( std::forward<Args>(args)... ); }

    // pop e lement out of the stack and return its value
    T pop()
        {
            if( c.empty() ){
                throw ReadEmptyStack();
            }
            T elem(c.back());
            c.pop_back();
            return elem;
        }

    // return value of next element
    T& top()
        {
            if( c.empty() ){
                throw ReadEmptyStack();
            }
            return c.back();
        }
};

#endif /* STACK_HPP */
