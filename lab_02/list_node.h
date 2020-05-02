#ifndef __LIST_NODE_H__
#define __LIST_NODE_H__

#include "errors.h"

template <typename T>
class list_node
{
public:
    list_node();
    list_node(const T &data);
    list_node(std::shared_ptr<list_node<T>> &node);

    ~list_node() = default;

    void set(const T &data);
    void set_next(const std::shared_ptr<list_node<T>> &node);
    void set_null();

    const T &get() const;
    T &get_value();
    std::shared_ptr<list_node<T>> get_next();

    bool operator == (const std::shared_ptr<list_node<T>> &node) const;
    bool operator != (const std::shared_ptr<list_node<T>> &node) const;

private:
    T data;
    std::shared_ptr<list_node<T>> next;
};

#include "list_node.hpp"

#endif
