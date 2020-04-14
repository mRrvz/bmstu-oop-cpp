#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

#include "base_iterator.h"

template <typename T>
class const_list_iterator : base_iterator
{
public:
    const_list_iterator();
    const_list_iterator(std::shared_ptr<list_node<T>> &node);
    const_list_iterator(const list_iterator<T> &iterator);

    ~const_list_iterator() = default;

    std::shared_ptr<list_node<T>> operator ->();
    const T &operator *() const;

    const_list_iterator<T> &operator += (size_t size);
    const_list_iterator<T> operator + (size_t size);
    const_list_iterator<T> operator = (const_list_iterator<T> &iterator);
    const_list_iterator<T> &operator ++ ();

    bool operator != (const_list_iterator<T> &iterator) const;
    bool operator == (const_list_iterator<T> &iterator) const;
    bool operator <= (const_list_iterator<T> &iterator) const;
    bool operator >= (const_list_iterator<T> &iterator) const;
    bool operator <  (const_list_iterator<T> &iterator) const;
    bool operator >  (const_list_iterator<T> &iterator) const;

protected:
    std::weak_ptr<list_node<T>> ptr;
};

#endif
