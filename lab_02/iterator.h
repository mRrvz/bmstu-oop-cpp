#ifndef __ITERATOR_H__
#define __ITERATOR_H__

#include <memory>

#include "list_node.h"
#include "base_iterator.h"

template <typename T>
class list_iterator : base_iterator
{
public:
    list_iterator();
    list_iterator(std::shared_ptr<list_node<T>> &node);
    list_iterator(const list_iterator<T> &iterator);

    ~list_iterator() = default;

    void next(void);

    std::shared_ptr<list_node<T>> operator ->();
    const T &operator *() const;

    list_iterator<T> &operator += (size_t size);
    list_iterator<T> operator + (size_t size);
    list_iterator<T> operator = (list_iterator<T> &iterator);
    list_iterator<T> &operator ++ ();

    bool operator != (list_iterator<T> &iterator) const;
    bool operator == (list_iterator<T> &iterator) const;
    bool operator <= (list_iterator<T> &iterator) const;
    bool operator >= (list_iterator<T> &iterator) const;
    bool operator <  (list_iterator<T> &iterator) const;
    bool operator >  (list_iterator<T> &iterator) const;

private:
    std::weak_ptr<list_node<T>> ptr;
};

#include "iterator.hpp"

#endif
