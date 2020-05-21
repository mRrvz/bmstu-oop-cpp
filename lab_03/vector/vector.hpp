#ifndef VECTOR_HPP
#define VECTOR_HPP

    #include <QDebug>
#include "vector.h"
#include "iterator.h"

template <typename T>
vector<T>::vector()
{
    this->size = 0;
}

template <typename T>
vector<T>::vector(const T *array, size_t _size)
{
    //this->size = _size;
    this->allocate_new(_size * 2);

    for (int i = 0; i < _size; i++)
    {
        this->push_back(*(array + i));
    }
}

template <typename T>
vector<T>::vector(T elem, size_t _size)
{
    //this->size = _size;
    this->allocate_new(_size * 2);

    for (int i = 0; i < _size; i++)
    {
        this->push_back(elem);
    }
}

template <typename T>
size_t vector<T>::get_size()
{
    return this->size;
}

template <typename T>
bool vector<T>::is_empty()
{
    return this->size == 0 ? true : false;
}

template <typename T>
T &vector<T>::at(size_t index)
{
    if (index >= this->size)
    {
        //todo
    }

    return this->value[index];
}

template <typename T>
vector<T> &vector<T>::push_back(const T &elem)
{
    if (memory_allocated > size)
    {
        allocate_new(size * 2);
    }

    //qDebug() << this->size;
    this->value[this->size++] = elem;
    //qDebug() << this->size << this->value[this->size - 1];
}

template <typename T>
vector<T> &vector<T>::operator += (const T &elem)
{
    this->push_back(elem);
}

template <typename T>
void vector<T>::remove(iterator<T>)
{

}

template <typename T>
void vector<T>::remove(size_t index)
{

}

template <typename T>
iterator<T> vector<T>::begin()
{
    iterator<T> iterator(*this);
    return iterator;
}

template <typename T>
iterator<T> vector<T>::end()
{
    iterator<T> iterator(*this);
    return iterator + this->size;
}

template <typename T>
void vector<T>::allocate_new(size_t size)
{
    try {
        this->value.reset(new T[size]);
    } catch (std::bad_alloc &exception) {
        //throw MemoryException(__FILE__, typeid(*this).name(),
        //                      __LINE__, ctime(&currentTime));

    }

    this->memory_allocated = size;
}

#endif
