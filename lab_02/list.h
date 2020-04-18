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
    list(list<T> &&list);
    list(list<T> &list);
    list(T *const array, const size_t &size);
    list(std::initializer_list<T> nodes);
    list(const list_iterator<T> &begin, const list_iterator <T>&end);

    ~list() = default;

    virtual bool is_empty(void) const;
    virtual size_t get_size(void) const;
    virtual void clear(void);

    void push_front(const T &data);
    void push_front(const list<T> &list);

    void insert(const list_iterator<T> &iterator, const T &data);
    void insert(const list_iterator<T> &iterator, const list<T> &list);
    void insert(const const_list_iterator<T> &iterator, const T &data);
    void insert(const const_list_iterator<T> &iterator, const list<T> &list);

    void push_back(const T &data);
    void push_back(const list<T> &list);

    void pop_front(void);
    void pop_back(void);
    void remove(const list_iterator<T> &iterator);

    void resize(const size_t &size);
    void reverse(void);

    bool operator == (const list<T> &list) const;
    bool operator != (const list<T> &list) const;

    list<T> &operator = (const list<T> &list);
    list<T> &operator = (const list<T> &&list);
    list<T> &operator += (const list<T> &list);
    list<T> &operator + (const list<T> &list);

    list_iterator<T> begin(void);
    const_list_iterator<T> cbegin(void) const;

    list_iterator<T> end(void);
    const_list_iterator<T> cend(void) const;

protected:
    std::shared_ptr<list_node<T>> get_head(void);
    std::shared_ptr<list_node<T>> get_tail(void);
    void push_back(const std::shared_ptr<list_node<T>> &node);
    void push_front(const std::shared_ptr<list_node<T>> &node);

private:
    size_t size;
    std::shared_ptr<list_node<T>> head;
    std::shared_ptr<list_node<T>> tail;
};

#include "list.hpp"

#endif
