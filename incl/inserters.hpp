#ifndef INSERTERS_HPP_
#define INSERTERS_HPP_

#include <iterator>

template<typename Cont>
class backinserter 
    : public std::iterator<std::output_iterator_tag, void,void,void,void>
{
public:
    backinserter(Cont& coll)
        : coll_(coll)
        { }
    backinserter& operator*()
        { return *this; }
    backinserter& operator++()
        { return *this; }
    backinserter& operator++(int)
        { return *this; }
    // template<typename T>
    // backinserter& operator=(const T& val)
    //     { 
    //         coll.push_back(val);
    //         return *this;
    //     }
    backinserter& operator=(const typename Cont::value_type& val)
        {
            coll_.push_back(val);
            return *this;
        }
    backinserter& operator=(typename Cont::value_type&& val)
        {
            coll_.push_back(std::move(val));
            return *this;
        }
private:
    Cont& coll_;
};

template<typename Cont>
constexpr backinserter<Cont> make_backinserter(Cont& coll)
{
    return backinserter<Cont>(coll);
}


template<typename Cont>
class frontinserter
    : public std::iterator<std::output_iterator_tag, void,void,void,void>
{
public:
    frontinserter(Cont& coll)
        : coll_(coll)
        { }
    frontinserter& operator*()
        { return *this; }
    frontinserter& operator++()
        { return *this; }
    frontinserter& operator++(int)
        { return *this; }
    frontinserter& operator=(const typename Cont::value_type& val)
        {
            coll_.push_back(val);
            return *this;
        }
    frontinserter& operator=(typename Cont::value_type&& val)
        {
            coll_.push_back(std::move(val));
            return *this;
        }
private:
    Cont& coll_;
};

template<typename Cont>
constexpr frontinserter<Cont> make_frontinserter(Cont& coll)
{
    return frontinserter<Cont>(coll);
}


template<typename Cont>
class myinserter
    : public std::iterator<std::output_iterator_tag, void,void,void,void>
{
public:
    myinserter(Cont& coll, typename Cont::iterator iter)
        : coll_(coll), pos(iter)
        { }
    myinserter& operator*()
        { return *this; }
    myinserter& operator++()
        { return *this; }
    myinserter& operator++(int)
        { return *this; }
    myinserter& operator=(const typename Cont::value_type& val)
    {
        pos = coll_.insert(pos, val);
        ++pos;
        return *this;
    }
    myinserter& operator=(typename Cont::value_type&& val)
    {
        pos = coll_.insert(pos, std::move(val));
        ++pos;
        return *this;
    }
private:
    Cont& coll_;
    typename Cont::iterator pos;
};

template<typename Cont>
constexpr myinserter<Cont> make_myinserter(Cont& coll, typename Cont::iterator iter)
{
    return myinserter<Cont>(coll, iter);
}

#endif /* INSERTERS_HPP_ */
