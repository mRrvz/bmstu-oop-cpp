#ifndef __LIST_NODE_HPP__
#define __LIST_NODE_HPP__

template <typename T>
list_node<T>::list_node()
{
    this->next = nullptr;
}

template <typename T>
list_node<T>::list_node(const T &data)
{
    this->next = nullptr;
    this->data = data;
}

template <typename T>
list_node<T>::list_node(std::shared_ptr<list_node<T>> &node)
{
    this->next = node->next;
    this->data = node->data;
}

template <typename T>
void list_node<T>::set(const T &data)
{
    this->data = data;
}

template <typename T>
void list_node<T>::set_next(const std::shared_ptr<list_node<T>> &node)
{
    this->next = node;
}

template <typename T>
void list_node<T>::set_next(const list_node<T> &node)
{
    std::shared_ptr<list_node<T>> node_ptr(node);
    this->next = node_ptr;
}

template <typename T>
void list_node<T>::set_null(void)
{
    this->next = nullptr;
}

template <typename T>
const T &list_node<T>::get(void) const
{
    return this->data;
}

template <typename T>
T &list_node<T>::get_value(void)
{
    return this->data;
}

template <typename T>
std::shared_ptr<list_node<T>> list_node<T>::get_next(void) const
{
    return this->next;
}

template <typename T>
bool list_node<T>::operator == (const std::shared_ptr<list_node<T>> &node) const
{
    return this == node;
}

template <typename T>
bool list_node<T>::operator != (const std::shared_ptr<list_node<T>> &node) const
{
    return this != node;
}

#endif
