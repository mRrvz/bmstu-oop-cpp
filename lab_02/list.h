#ifndef __LIST_H__
#define __LIST_H__

#include <initializer_list>
#include <memory>
#include <chrono>

#include "base_container.h"
#include "list_node.h"
#include "iterator.h"
#include "const_iterator.h"
#include "errors.h"

template <typename T>
class list : public base_container
{
public:
    list();

    list(list<T> &list);
    list<T> &operator = (const list<T> &list);

    list(list<T> &&list);
    list<T> &operator = (const list<T> &&list);

    list(T *const array, const int &size);
    list(std::initializer_list<T> nodes);

    list(const std::iterator<std::input_iterator_tag, T> &begin, const std::iterator<std::input_iterator_tag, T> &end);
    //list(const std::iterator<std::output_iterator_tag, T> &begin, const std::iterator<std::output_iterator_tag, T> &end);

    ~list() = default;

    virtual bool is_empty() const;
    virtual void clear();

    list_iterator<T> push_front(const T &data);
    list_iterator<T> push_front(const list<T> &list);

    list_iterator<T> insert(const list_iterator<T> &iterator, const T &data);
    list_iterator<T> insert(const list_iterator<T> &iterator, const list<T> &list);
    list_iterator<T> insert(const const_list_iterator<T> &iterator, const T &data);
    list_iterator<T> insert(const const_list_iterator<T> &iterator, const list<T> &list);

    list_iterator<T> push_back(const T &data);
    list_iterator<T> push_back(const list<T> &list);

    T pop_front();
    T pop_back();
    T remove(const list_iterator<T> &iterator);

    void reverse();

    list<T> &merge(const list<T> &list);
    list<T> &merge(const T &data);

    list<T> &operator += (const list<T> &list);
    list<T> &operator += (const T &data);

    list<T> &operator + (const list<T> &list);
    list<T> &operator + (const T &data);

    bool operator == (const list<T> &list) const;
    bool operator != (const list<T> &list) const;

    list_iterator<T> begin();
    const_list_iterator<T> cbegin() const;

    list_iterator<T> end();
    const_list_iterator<T> cend() const;

protected:
    std::shared_ptr<list_node<T>> get_head();
    std::shared_ptr<list_node<T>> get_tail();
    list_iterator<T> push_back(const std::shared_ptr<list_node<T>> &node);
    list_iterator<T> push_front(const std::shared_ptr<list_node<T>> &node);

private:
    size_t size;
    std::shared_ptr<list_node<T>> head;
    std::shared_ptr<list_node<T>> tail;
};

#include "list.hpp"

#endif
