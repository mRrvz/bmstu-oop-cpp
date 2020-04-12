#ifndef __LIST_H__
#define __LIST_H__

#include <initializer_list>
#include <memory>

#include "base_container.h"
#include "list_node.h"

template <typename T>
class list : public base_container
{
public:
    list();
    list(set<T> &&set);
    list(const set<T> &set);
    list(T *array, size_t size);
    list(std::initializer_list<T> args);
    list(iterator<T> &begin, iterator <T>&end);

    ~list();

    bool is_empty() const;
    size_t size() const;
    void clear();

    void push_front(const T &data);
    void push_front(const list<T> &list);

    void insert(iterator<T> &iterator, const T &data);
    void insert(iterator<T> &iterator, const list<T> &list);

    void insert(const_iterator<T> &iterator, const T &data);
    void insert(const_iterator<T> &iterator, const list<T> &list)

    void push_back(const T &data);
    void push_back(const list<T> &list);

    void pop_front(void);
    void pop_back(void);
    void remove(iterator<T> &iterator);

    void resize(const size_t &size);
    void revesre(void);

    bool operator == (const list<T> &list) const;
    bool operator != (const list<T> &list) const;

    list<T> &operator = (const list<T> &list);
    list<T> &operator += (const list<T> &list);
    list<T> &operator + (const list<T> &list);

    iterator<T> begin();
    const_iterator<T> cbegin() const;

    iterator<T> end();
    const_iterator<T> cend() const;

protected:
    std::shared_ptr<list_node<T>> head(void);
    std::shared_ptr<list_node<T>> tail(void);

private:
    size_t size;
    std::shared_ptr<list_node<T>> head;
    std::shared_ptr<list_node<T>> tail;
};

#endif
