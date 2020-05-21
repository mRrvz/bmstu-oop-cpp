#include "composite.h"

composite::composite(component &component)
{
    this->components.push_back(component);
}

composite::composite(vector<component> vector)
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

bool composite::add(const component &component)
{
    this->components.push_back(component);
    return false;
};

bool composite::remove(const iterator<component> &iterator)
{
    components.remove(iterator);
    return false;
};

iterator<component> composite::begin()
{
    return components.begin();
};

iterator<component> composite::end()
{
    return components.end();
};

bool composite::is_composite() const
{
    return true;
};
