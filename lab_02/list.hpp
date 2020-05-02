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
list<T>::list(list<T> &list)
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto node: list)
    {
        std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
        if (!temp_node)
        {
            auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
            throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
        }

        temp_node->set(node);
        this->push_back(temp_node);
    }
}

template <typename T>
list<T>::list(T *const array, const size_t &size)
{
    if (!array)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw pointer_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    if (size <= 0)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw size_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (int i = 0; i < size; i++)
    {
        this->push_back(*(array + i));
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
        this->push_back(node);
    }
}


template <typename T>
template <typename T_>
list<T>::list(const T_ &begin, const T_ &end)
{
    if (begin.is_invalid() || end.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (auto current = begin; current != end + 1; current++)
    {
        this->push_back(*current);
    }
}

template <typename T>
bool list<T>::is_empty(void) const
{
    return 0 == this->size;
}

template <typename T>
void list<T>::clear(void)
{
    while (this->size)
    {
        this->pop_front();
    }
}

template <typename T>
list_iterator<T> list<T>::push_front(const T &data)
{
    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    temp_node->set(data);
    return this->push_front(temp_node);
}

template <typename T>
list_iterator<T> list<T>::push_front(const std::shared_ptr<list_node<T>> &node)
{
    if (!node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw pointer_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    node->set_next(this->head);
    this->head = node;

    if (!this->size)
    {
        this->tail = this->head;
    }

    this->size++;

    list_iterator<T> iterator(node);
    return iterator;
}

template <typename T>
list_iterator<T> list<T>::push_front(const list<T> &list)
{
    list_iterator<T> iterator;

    for (int i = 0; i < list.size; i++)
    {
        iterator = this->insert(this->begin() + i, *(list.cbegin() + i));
    }

    return iterator;
}

template <typename T>
list_iterator<T> list<T>::insert(const list_iterator<T> &iterator, const T &data)
{
    if (iterator.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    temp_node->set(data);

    if (iterator == this->begin())
    {
        return push_front(temp_node);
    }
    else if (iterator == this->end())
    {
        return this->push_back(temp_node);
    }

    list_iterator<T> temp_iterator = this->begin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    temp_node->set_next(temp_iterator->get_next());
    temp_iterator->set_next(temp_node);
    this->size++;

    list_iterator<T> insert_iterator(temp_node);
    return insert_iterator;
}


template <typename T>
list_iterator<T> list<T>::insert(const list_iterator<T> &iterator, const list<T> &list)
{
    if (iterator.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    list_iterator<T> insert_iterator;

    for (int i = 0; i < list.size; i++)
    {
        insert_iterator = insert(iterator, *(list.cbegin() + i));
    }

    return insert_iterator;
}

template <typename T>
list_iterator<T> list<T>::insert(const const_list_iterator<T> &iterator, const T &data)
{
    if (iterator.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    temp_node->set(data);

    if (iterator == this->cbegin())
    {
        return push_front(temp_node);
    }
    else if (iterator == this->cend())
    {
        return this->push_back(temp_node);
    }

    const_list_iterator<T> temp_iterator = this->cbegin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    temp_node->set_next(temp_iterator->get_next());
    temp_iterator->set_next(temp_node);
    this->size++;

    list_iterator<T> insert_iterator(temp_node);
    return insert_iterator;
}

template <typename T>
list_iterator<T> list<T>::insert(const const_list_iterator<T> &iterator, const list<T> &list)
{
    if (iterator.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    list_iterator<T> insert_iterator;

    for (int i = 0; i < list.size; i++)
    {
        insert_iterator = insert(iterator, *(list.cbegin() + i));
    }

    return insert_iterator;
}

template <typename T>
list_iterator<T> list<T>::push_back(const list<T> &list)
{
    for (auto current = list.cbegin(); current != list.cend(); current++)
    {
        this->push_back(*current);
    }

    list_iterator<T> iterator(this->tail);
    return iterator;
}

template <typename T>
list_iterator<T> list<T>::push_back(const T &data)
{
    std::shared_ptr<list_node<T>> node(new list_node<T>);
    if (!node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    node->set(data);
    return this->push_back(node);
}

template <typename T>
list_iterator<T> list<T>::push_back(const std::shared_ptr<list_node<T>> &node)
{
    if (!node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw pointer_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw memory_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    temp_node->set(node->get());

    if (!this->size)
    {
        this->head = temp_node;
        this->tail = temp_node;
    }
    else
    {
        this->tail->set_next(temp_node);
        this->tail = temp_node;
    }

    this->size++;

    list_iterator<T> iterator(this->tail);
    return iterator;
}

template <typename T>
T list<T>::pop_front(void)
{
    if (!this->size)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw empty_list(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    T data = this->head->get();

    if (this->size == 1)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        this->head = this->head->get_next();
    }

    this->size--;

    return data;
}

template <typename T>
T list<T>::pop_back(void)
{
    if (!this->size)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw empty_list(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    T data = this->tail->get();

    if (this->size == 1)
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    else
    {
        std::shared_ptr<list_node<T>> temp_node = this->head;
        for (; temp_node->get_next() != this->tail; temp_node = temp_node->get_next());

        temp_node->set_null();
        this->tail = temp_node;
        this->tail->set_null();
    }

    this->size--;

    return data;
}

template <typename T>
T list<T>::remove(const list_iterator<T> &iterator)
{
    if (iterator.is_invalid())
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw iterator_error(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    if (!this->size)
    {
        auto timenow = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        throw empty_list(ctime(&timenow), __FILE__, typeid(list).name(), __FUNCTION__);
    }

    if (iterator == this->begin())
    {
        return pop_front();
    }

    list_iterator<T> temp_iterator = this->begin();
    for (; temp_iterator + 1 != iterator; temp_iterator++);

    T data = temp_iterator->get();
    temp_iterator->set_next(temp_iterator->get_next()->get_next());
    this->size--;

    return data;
}

template <typename T>
list<T> &list<T>::merge(const list<T> &list)
{
    this->push_back(list);
    return *this;
}

template <typename T>
list<T> &list<T>::merge(const T &data)
{
    this->push_back(data);
    return *this;
}

template <typename T>
void list<T>::reverse(void)
{
    std::shared_ptr<list_node<T>> current(this->head);
    std::shared_ptr<list_node<T>> next(nullptr);
    std::shared_ptr<list_node<T>> prev(nullptr);

    while (current)
    {
        next = current->get_next();
        current->set_next(prev);
        prev = current;
        current = next;
    }

    prev = this->head;
    this->head = this->tail;
    this->tail = prev;
    this->tail->set_null();
}

template <typename T>
bool list<T>::operator == (const list<T> &list) const
{
    auto fst = this->cbegin();
    auto snd = list.cbegin();

    for (; fst != this->cend() && snd != list.cend(); ++fst, ++snd)
    {
        if (fst->get() != snd->get())
        {
            return false;
        }
    }

    return this->size == list.size;
}

template <typename T>
bool list<T>::operator != (const list<T> &list) const
{
    return !(*this == list);
}


template <typename T>
list<T> &list<T>::operator = (const list<T> &list)
{
    clear();

    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    push_back(list);
    return *this;
}

template <typename T>
list<T> &list<T>::operator = (const list<T> &&list)
{
    this->size = list.size;
    this->head = list.head;
    this->tail = list.tail;
}

template <typename T>
list<T> &list<T>::operator += (const list<T> &list)
{
    this->push_back(list);
    return *this;
}

template <typename T>
list<T> &list<T>::operator += (const T &data)
{
    this->push_back(data);
    return *this;
}

template <typename T>
list<T> &list<T>::operator + (const list<T> &list)
{
    this->push_back(list);
    return *this;
}

template <typename T>
list<T> &list<T>::operator + (const T &data)
{
    this->push_back(data);
    return *this;
}

template<typename T_>
std::ostream &operator << (std::ostream &os, const list<T_> &list)
{
    for (auto iterator = list.cbegin(); iterator != list.cend(); iterator++)
    {
        os << *iterator << " ";
    }

    return os;
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
