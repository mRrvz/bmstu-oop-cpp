#include "composite.h"

composite::composite(std::shared_ptr<component> &component)
{
    this->components.push_back(component);
}

composite::composite(vector<std::shared_ptr<component>> vector)
{
    this->components = vector;
}

/*
void composite::operatrion() const
{
    for (auto element: components)
    {
        element.operation();
    }
}
*/

bool composite::add(const std::shared_ptr<component> &component)
{
    this->components.push_back(component);
    return true;
};

bool composite::remove(const iterator<std::shared_ptr<component>> &iterator)
{
    components.remove(iterator);
    return true;
};

iterator<std::shared_ptr<component>> composite::begin()
{
    return components.begin();
};

iterator<std::shared_ptr<component>> composite::end()
{
    return components.end();
};

bool composite::is_composite() const
{
    return true;
};

size_t composite::size() const
{
    return this->components.get_size();
}
