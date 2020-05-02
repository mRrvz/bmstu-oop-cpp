#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <iterator>
#include "list_node.h"

template <typename T>
class list_iterator : std::iterator<std::input_iterator_tag, T>
{
public:
    list_iterator();
    list_iterator(const std::shared_ptr<list_node<T>> &node);
    list_iterator(const list_iterator<T> &iterator);

    ~list_iterator() = default;

    virtual void next();
    virtual bool is_invalid() const;

    std::shared_ptr<list_node<T>> operator ->(); // ?
    T &operator *() const;
    operator bool() const;

    list_iterator<T> &operator += (const int &size);
    list_iterator<T> operator + (const int &size) const;
    list_iterator<T> operator = (const list_iterator<T> &iterator);
    list_iterator<T> &operator ++ ();
    list_iterator<T> operator ++ (int);

    bool operator != (const list_iterator<T> &iterator) const;
    bool operator == (const list_iterator<T> &iterator) const;

private:
    std::weak_ptr<list_node<T>> ptr;
};

#include "iterator.hpp"

#endif
