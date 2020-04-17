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
            //throw;
        }

        temp_node->set(node);
        this->append(temp_node);
    }
}

template <typename T>
list<T>::list(T *array, size_t size)
{
    if (!array || size <= 0)
    {
        std::cout << "ERR";
    }

    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;

    for (int i = 0; i < size; i++)
    {
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

    for (auto current = begin; current != end; current++)
    {
        this->append(*current);
    }
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
    while (this->size)
    {
        this->pop_front();
    }
}

template <typename T>
void list<T>::push_front(const T &data)
{
    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {

    }

    temp_node->set(data);
    this->push_front(temp_node);
}

template <typename T>
void list<T>::push_front(const std::shared_ptr<list_node<T>> &node)
{
    node->set_next(this->head);
    this->head = node;
    this->size++;
}

template <typename T>
void list<T>::push_front(list<T> &list)
{
    for (int i = 0; i < list.get_size(); i++)
    {
        this->insert(this->begin() + i, *(list.begin() + i));
    }
}


template <typename T>
void list<T>::insert(const list_iterator<T> &iterator, const T &data)
{
    // if ?
    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {

    }

    temp_node->set(data);

    if (iterator == this->begin())
    {
        push_front(temp_node);
    }
    else if (iterator == this->end())
    {
        this->append(temp_node);
    }
    else
    {
        list_iterator<T> temp_iterator = this->begin();
        for (; temp_iterator + 1 != iterator; temp_iterator++);

        temp_node->set_next(temp_iterator->get_next());
        temp_iterator->set_next(temp_node);
        this->size++;
    }
}


template <typename T>
void list<T>::insert(const list_iterator<T> &iterator, const list<T> &list)
{
    for (int i = 0; i < list.get_size(); i++)
    {
        insert(iterator, *(list.cbegin() + i));
    }
}

template <typename T>
void list<T>::insert(const const_list_iterator<T> &iterator, const T &data)
{
    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {

    }

    temp_node->set(data);

    if (iterator == this->cbegin())
    {
        push_front(temp_node);
    }
    else if (iterator == this->cend())
    {
        this->append(temp_node);
    }
    else
    {
        const_list_iterator<T> temp_iterator = this->cbegin();
        for (; temp_iterator + 1 != iterator; temp_iterator++);

        temp_node->set_next(temp_iterator->get_next());
        temp_iterator->set_next(temp_node);
        this->size++;
    }
}

template <typename T>
void list<T>::insert(const const_list_iterator<T> &iterator, const list<T> &list)
{
    for (int i = 0; i < list.get_size(); i++)
    {
        insert(iterator, *(list.cbegin() + i));
    }
}

template <typename T>
void list<T>::push_back(const T &data)
{
    std::shared_ptr<list_node<T>> temp_node(new list_node<T>);
    if (!temp_node)
    {

    }

    temp_node->set(data);
    this->push_back(temp_node);
}

template <typename T>
void list<T>::push_back(const std::shared_ptr<list_node<T>> &node)
{
    this->append(node);
}

template <typename T>
void list<T>::push_back(list<T> &list)
{
    for (auto node: list)
    {
        this->append(node);
    }
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
    this->append(temp_node);
}

template <typename T>
void list<T>::append(const list_node<T> &node)
{
    std::shared_ptr <list_node<T>> temp_node(new list_node<T>);
    if (temp_node == nullptr)
    {
        //throw
    }

    temp_node->set(node.get());

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
}

template <typename T>
void list<T>::append(const list<T> &list)
{
    this->push_back(list);
}

template <typename T>
void list<T>::pop_front(void)
{
    if (!this->size)
    {

    }

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
}

template <typename T>
void list<T>::pop_back(void)
{
    if (!this->size)
    {

    }

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
}

template <typename T>
void list<T>::remove(const list_iterator<T> &iterator)
{
    if (iterator == this->begin())
    {
        pop_front();
    }
    else
    {
        list_iterator<T> temp_iterator = this->begin();
        for (; temp_iterator + 1 != iterator; temp_iterator++);

        temp_iterator->set_next(temp_iterator->get_next()->get_next());
        this->size--;
    }
}

template <typename T>
void list<T>::resize(const size_t &size)
{
    if (size <= 0)
    {
        //throw
    }

    for (int i = 0; i < size && get_size(); i++)
    {
        pop_back();
        this->size--;
    }
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

    return this->size == list.get_size();
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
    this->append(list);
    return *this;
}

template <typename T>
list<T> &list<T>::operator + (const list<T> &list)
{
    this->append(list);
    return *this;
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
