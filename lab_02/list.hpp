#ifndef __LIST_HPP__
#define __LIST_HPP__

#include "list.h"

template <typename T>
list<T>::list()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <typename T>
list<T>::list(list<T> &&list)
{
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}

template <typename T>
list<T>::list(const list<T> &list)
{

}

template <typename T>
list<T>::list(T *array, size_t size)
{

}

template <typename T>
list<T>::list(std::initializer_list<T> args)
{

}

template <typename T>
list<T>::list(iterator<T> begin, iterator<T> end)
{

}

template <typename T>
list<T>::~list()
{
    //delete

}


template <typename T>
bool list<T>::is_empty() const
{
    return 0 == this->size;
}

template <typename T>
size_t list<T>::size() const
{
    return this->size;
}

template <typename T>
void list<T>::clear()
{
    //addd
}

template <typename T>
void list<T>::push_front(const T &data)
{

}

template <typename T>
void list<T>::push_front(const list<T> &list)
{

}


template <typename T>
void list<T>::insert(iterator<T> &iterator, const T &data)
{

}

template <typename T>
void list<T>::insert(iterator<T> &iterator, const list<T> &list)
{

}

template <typename T>
void list<T>::insert(const_interator<T> &iterator, const T &data)
{

}

template <typename T>
void list<T>::insert(const_interator<T> &iterator, const list<T> &list)
{

}

template <typename T>
void list<T>::push_back(const T &data)
{

}

template <typename T>
void list<T>::push_back(const list<T> &list)
{

}

template <typename T>
void list<T>::pop_front(void)
{

}

template <typename T>
void list<T>::pop_back(void)
{

}

template <typename T>
void list<T>::remove(iterator<T> &iterator)
{

}

template <typename T>
void list<T>::resize(const size_t &size)
{

}

template <typename T>
void list<T>::revesre(void)
{

}

template <typename T>
bool list<T>::operator == (const list<T> &list) const
{

}

template <typename T>
bool list<T>::operator != (const list<T> &list) const
{

}


template <typename T>
list<T> list<T>::&operator = (const list<T> &list)
{

}

template <typename T>
list<T> list<T>::&operator += (const list<T> &list)
{

}

template <typename T>
list<T> list<T>::&operator + (const list<T> &list)
{

}

template <typename T>
iterator<T> list<T>::begin()
{

}

template <typename T>
const_iterator<T> list<T>::cbegin() const
{

}

template <typename T>
iterator<T> list<T>::end()
{

}

template <typename T>
const_iterator<T> list<T>::cend() const
{

}

template <typename T>
std::shared_ptr<list_node<T>> list<T>::head(void)
{
    return this->head;
}

template <typename T>
std::shared_ptr<list_node<T>> list<T>::tail(void)
{
    return this->tail;
}

#endif
