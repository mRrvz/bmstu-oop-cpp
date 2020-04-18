#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

#include "base_iterator.h"

template <typename T>
class const_list_iterator : base_iterator
{
public:
    const_list_iterator();
    const_list_iterator(const std::shared_ptr<list_node<T>> &node);
    const_list_iterator(const const_list_iterator<T> &iterator);

    ~const_list_iterator() = default;

    virtual void next(void);
    virtual bool is_invalid(void) const;

    const std::shared_ptr<list_node<T>> operator ->() const;
    const T &operator *() const;

    const_list_iterator<T> &operator += (const size_t &size);
    const_list_iterator<T> operator + (const size_t &size) const;
    const_list_iterator<T> operator = (const list_iterator<T> &iterator);
    const_list_iterator<T> &operator ++ ();
    const_list_iterator<T> operator ++ (int);

    bool operator != (const const_list_iterator<T> &iterator) const;
    bool operator == (const const_list_iterator<T> &iterator) const;
    bool operator <= (const const_list_iterator<T> &iterator) const;
    bool operator >= (const const_list_iterator<T> &iterator) const;
    bool operator <  (const const_list_iterator<T> &iterator) const;
    bool operator >  (const const_list_iterator<T> &iterator) const;

protected:
    std::weak_ptr<list_node<T>> ptr;
};

#include "const_iterator.hpp"

#endif
