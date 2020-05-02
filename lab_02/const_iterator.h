#ifndef __CONST_ITERATOR_H__
#define __CONST_ITERATOR_H__

#include <iterator>

template <typename T>
class const_list_iterator : std::iterator<std::input_iterator_tag, T>
{
public:
    const_list_iterator();
    const_list_iterator(const std::shared_ptr<list_node<T>> &node);
    const_list_iterator(const const_list_iterator<T> &iterator);

    ~const_list_iterator() = default;

    virtual void next();
    virtual bool is_invalid() const;

    const list_node<T> *operator ->() const;
    const list_node<T> &operator *() const;
    operator bool() const;

    const_list_iterator<T> &operator += (const int &size);
    const_list_iterator<T> operator + (const int &size) const;
    const_list_iterator<T> operator = (const list_iterator<T> &iterator);
    const_list_iterator<T> &operator ++ ();
    const_list_iterator<T> operator ++ (int);

    bool operator != (const const_list_iterator<T> &iterator) const;
    bool operator == (const const_list_iterator<T> &iterator) const;

protected:
    std::weak_ptr<list_node<T>> ptr;
};

#include "const_iterator.hpp"

#endif
