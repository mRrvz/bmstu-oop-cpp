#ifndef __ITERATOR_HPP__
#define __ITERATOR_HPP__

template <typename T>
list_iterator<T>::list_iterator()
{
    this->ptr = nullptr;
}

template <typename T>
list_iterator<T>::list_iterator(std::shared_ptr<list_node<T>> &node)
{
    this->ptr = node;
}

template <typename T>
list_iterator<T>::list_iterator(const list_iterator<T> &iterator)
{
    this->ptr = iterator.ptr.lock();
}

template <typename T>
void list_iterator<T>::next(void)
{
    this->ptr = this->ptr.lock()->get_next();
}

template <typename T>
std::shared_ptr<list_node<T>> list_iterator<T>::operator ->()
{
    return this->ptr;
}

template <typename T>
const T &list_iterator<T>::operator *() const
{
    return this->ptr.lock()->get();
}

template <typename T>
list_iterator<T> &list_iterator<T>::operator += (size_t size)
{
    while (size--)
    {
        this->next();
    }

    return *this;
}

template <typename T>
list_iterator<T> list_iterator<T>::operator + (size_t size)
{
    list_iterator<T> new_iterator(*this);
    new_iterator += size;
    return new_iterator;
}

template <typename T>
list_iterator<T> list_iterator<T>::operator = (list_iterator<T> &iterator)
{
    this-ptr = iterator.ptr.lock();
    return *this;
}

template <typename T>
list_iterator<T> &list_iterator<T>::operator ++ ()
{
    this->next();
    return *this;
}

template <typename T>
bool list_iterator<T>::operator != (list_iterator<T> &iterator) const
{
    return this->ptr.lock() != iterator.ptr.lock();
}

template <typename T>
bool list_iterator<T>::operator == (list_iterator<T> &iterator) const
{
    return this->ptr.lock() == iterator.ptr.lock();
}

template <typename T>
bool list_iterator<T>::operator <= (list_iterator<T> &iterator) const
{
    return this->ptr.lock() <= iterator.ptr.lock();
}

template <typename T>
bool list_iterator<T>::operator >= (list_iterator<T> &iterator) const
{
    return this->ptr.lock() >= iterator.ptr.lock();
}

template <typename T>
bool list_iterator<T>::operator < (list_iterator<T> &iterator) const
{
    return this->ptr.lock() < iterator.ptr.lock();
}

template <typename T>
bool list_iterator<T>::operator > (list_iterator<T> &iterator) const
{
    return this->ptr.lock() > iterator.ptr.lock();
}

#endif
