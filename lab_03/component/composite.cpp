#include "composite.h"

composite::composite(std::shared_ptr<component> &component)
{
    this->components.push_back(component);
}

composite::composite(vector<std::shared_ptr<component>> vector)
{
    this->components = vector;
}

bool composite::add(const std::shared_ptr<component> &component)
{
    this->components.push_back(component);
    return true;
}

bool composite::remove(const iterator<std::shared_ptr<component>> &iterator)
{
    components.remove(iterator);
    return true;
}

iterator<std::shared_ptr<component>> composite::begin()
{
    return components.begin();
}

iterator<std::shared_ptr<component>> composite::end()
{
    return components.end();
}

bool composite::is_composite() const
{
    return true;
}

size_t composite::size() const
{
    return this->components.get_size();
}

void composite::draw(draw_manager &manager) const
{
    for (auto elem: components)
    {
        elem->draw(manager);
    }
}

void composite::reform(const point &move, const point &scale, const point &turn)
{
    for (auto elem: components)
    {
        elem->reform(move, scale, turn);
    }
}

cams_composite::cams_composite(std::shared_ptr<camera_obj> &component)
{
    this->objects.push_back(component);
}

cams_composite::cams_composite(vector<std::shared_ptr<camera_obj>> vector)
{
    this->objects = vector;
}

bool cams_composite::add(const std::shared_ptr<camera_obj> &component)
{
    this->objects.push_back(component);
    return true;
}

bool cams_composite::remove(const iterator<std::shared_ptr<camera_obj>> &iterator)
{
    this->objects.remove(iterator);
    return true;
}

iterator<std::shared_ptr<camera_obj>> cams_composite::begin()
{
    return this->objects.begin();
}

iterator<std::shared_ptr<camera_obj>> cams_composite::end()
{
    return this->objects.end();
}

bool cams_composite::is_composite() const
{
    return true;
}

size_t cams_composite::size() const
{
    return this->objects.get_size();
}

void cams_composite::reform(const point &new_pos)
{
    for (auto elem: this->objects)
    {
        elem->reform(new_pos);
    }
}
