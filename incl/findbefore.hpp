// Chapter 7 Containers -- forward_list findbefore algorithm


template<typename InputIterator, typename Tp>
inline InputIterator
find_before(InputIterator first, InputIterator last, const Tp& val)
{
    if(first==last){
        return first;
    }
    InputIterator next(first);
    ++next;
    while(next!=last && !(*next==val)){
        ++next;
        ++first;
    }
    return first;
}

template<typename InputIterator, typename Pred>
inline InputIterator
find_before_if(InputIterator first, InputIterator last, Pred pred)
{
    if(first==last){
        return first;
    }

    InputIterator next(first);
    ++next;
    while(next!=last && !(pred(*next))){
        ++next;
        ++first;
    }
    return first;
}
