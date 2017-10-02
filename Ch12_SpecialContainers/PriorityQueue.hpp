// Chapter 12 Special Containers -- implementation of a PriorityQueue
#ifndef PRIORITY_QUEUE_HPP_
#define PRIORITY_QUEUE_HPP_

#include <vector>
#include <algorithm>
#include <functional>
#include <exception>


template<typename T, typename Compare = std::less<T>>
class PriorityQueue
{
protected:
    std::vector<T>  c_;
    Compare         cmp_;
public:
/* typedefs */
    typedef std::vector<T>                          container_type;
    typedef typename std::vector<T>::size_type      size_type;
    typedef T                                       value_type;
    typedef T*                                      pointer;
    typedef const T*                                const_pointer;
    typedef T&                                      reference;
    typedef const T&                                const_reference;

/* constructors */
    explicit PriorityQueue( const Compare& cmp = Compare()
                          , const std::vector<T>& cont )
        : c_( cont )
        , cmp_( cmp )
        { std::make_heap(c_.begin(), c.end(), cmp_); }

    explicit PriorityQueue( const Compare& cmp = Compare()
                          , std::vector<T>&& cont )
        : c_( std::move(cont) )
        , cmp_( cmp )
        { std::make_heap( c_.begin(), c.end(), cmp_); }
    
    template<typename InIter>
    PriorityQueue( InIter beg, InIter end, const Compare& cmp )
        : c_( beg, end )
        , cmp_( cmp )
        { std::make_heap( c_.begin(), c_.end(), cmp_ ); }

    template<typename InIter>
    PriorityQueue( InIter beg, InIter end, const Compare& cmp
                 , const std::vector<T>& cont )
        : c_( cont )
        , cmp_( cmp )
        {
            c_.insert( beg, end )
            std::make_heap( c_.begin(), c_.end(), cmp_ );
        }

/*  */
    size_type size() const { return c_.size(); }

    bool empty() const { return c_.empty(); }

/* modifiers */
    void push( const value_type& val )
        {
            c_.push_back( val );
            std::push_heap( c_.begin(), c_.end(), cmp_ );
        }
    void push( value_type&& val )
        {
            c_.push_back( std::move(val) );
            std::push_heap( c_.begin(), c_.end(), cmp_ );
        }
    template<typename... Args>
    void emplace( Args&&... args )
        {
            c_.emplace_back( std::forward<Args>(args)... );
            std::push_heap( c_.begin(), c_.end(), cmp_ );
        }
    
    void pop()
        {
            std::pop_heap( c_.begin(), c_.end(), cmp_ );
            c_.pop_back();
        }

    reference top() { return c_.front(); }
    const_reference top() const { return c_.front(); }
};


#endif /* PRIORITY_QUEUE_HPP_ */
