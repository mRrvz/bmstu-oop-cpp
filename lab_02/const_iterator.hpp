#ifndef __CONST_ITERATOR_HPP__
#define __CONST_ITERATOR_HPP__

template <typename T>
const_list_iterator<T>::const_list_iterator()
{
    this->ptr = nullptr;
}

template <typename T>
const_list_iterator<T>::const_list_iterator(const std::shared_ptr<list_node<T>> &node)
{
    this->ptr = node;
}

template <typename T>
const_list_iterator<T>::const_list_iterator(const const_list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr.lock();
}

template <typename T>
void const_list_iterator<T>::next(void)
{
    this->ptr = this->ptr.lock()->get_next();
}


template <typename T>
const std::shared_ptr<list_node<T>> const_list_iterator<T>::operator ->() const
{
    return this->ptr.lock();
}


template <typename T>
const T &const_list_iterator<T>::operator *() const
{
    return this->ptr.lock()->get();
}

template <typename T>
const_list_iterator<T> &const_list_iterator<T>::operator += (size_t size)
{
    while (size--)
    {
        this->next();
    }

    return *this;
}

template <typename T>
const_list_iterator<T> const_list_iterator<T>::operator + (size_t size)
{
    const_list_iterator<T> new_iterator(*this);
    new_iterator += size;
    return new_iterator;
}

template <typename T>
const_list_iterator<T> &const_list_iterator<T>::operator ++ ()
{
    this->next();
    return *this;
}

template <typename T>
const_list_iterator<T> const_list_iterator<T>::operator ++ (int)
{
    const_list_iterator<T> new_iterator(*this);
    this->next();
    return new_iterator;
}

template <typename T>
bool const_list_iterator<T>::operator != (const const_list_iterator<T> &iterator) const
{
    return this->ptr.lock() != iterator.ptr.lock();
}

template <typename T>
bool const_list_iterator<T>::operator == (const const_list_iterator<T> &iterator) const
{
    return this->ptr.lock() == iterator.ptr.lock();
}


#endif
