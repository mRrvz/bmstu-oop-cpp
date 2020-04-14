#ifndef __LIST_HPP__
#define __LIST_HPP__

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
    if (!array || !size)
    {
        std::cout << "ERR";
    }

    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (int i = 0; i < size; i++)
    {
        std::cout << "FFF\n";
        this->append(array[i]);
    }
}

template <typename T>
list<T>::list(std::initializer_list<T> nodes)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto node: nodes)
    {
        this->append(node);
    }
}

template <typename T>
list<T>::list(list_iterator<T> &begin, list_iterator<T> &end)
{
    //throw

    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto current = begin; current != end; ++current)
    {
        this->append(*current);
    }
}

template <typename T>
list<T>::~list()
{
    //delete

}

template <typename T>
bool list<T>::is_empty(void) const
{
    return 0 == this->size;
}

template <typename T>
size_t list<T>::get_size(void) const
{
    return this->size;
}

template <typename T>
void list<T>::clear(void)
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
void list<T>::insert(list_iterator<T> &iterator, const T &data)
{

}

template <typename T>
void list<T>::insert(list_iterator<T> &iterator, const list<T> &list)
{

}

template <typename T>
void list<T>::insert(const_list_iterator<T> &iterator, const T &data)
{

}

template <typename T>
void list<T>::insert(const_list_iterator<T> &iterator1, const list<T> &list)
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
void list<T>::append(const T &data)
{
    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {
        std::cout << "err";
    }

    temp_node->set(data);
    std::cout << "xd";

    if (!this->size)
    {
        this->head = temp_node;
        this->tail = temp_node;
    }
    else
    {
        //std::shared_ptr<list_node<T>> temp_tail = this->tail;
        this->tail->set_next(temp_node);
        this->tail = temp_node;
    }

    this->size++;
}

template <typename T>
void list<T>::append(const list<T> &list)
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
void list<T>::remove(list_iterator<T> &iterator)
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
    return true;
}

template <typename T>
bool list<T>::operator != (const list<T> &list) const
{
    return true;
}


template <typename T>
list<T> &list<T>::operator = (const list<T> &list)
{

}

template <typename T>
list<T> &list<T>::operator += (const list<T> &list)
{

}

template <typename T>
list<T> &list<T>::operator + (const list<T> &list)
{

}

template <typename T>
list_iterator<T> list<T>::begin(void)
{
    list_iterator<T> iterator(this->head);
    return iterator;
}

template <typename T>
const_list_iterator<T> list<T>::cbegin(void) const
{
    const_list_iterator<T> iterator(this->head);
    return iterator;
}

template <typename T>
list_iterator<T> list<T>::end(void)
{
    list_iterator<T> iterator(this->tail);
    return ++iterator;
}

template <typename T>
const_list_iterator<T> list<T>::cend(void) const
{
    const_list_iterator<T> iterator(this->tail);
    return ++iterator;
}

template <typename T>
std::shared_ptr<list_node<T>> list<T>::get_head(void)
{
    return this->head;
}

template <typename T>
std::shared_ptr<list_node<T>> list<T>::get_tail(void)
{
    return this->tail;
}

#endif
