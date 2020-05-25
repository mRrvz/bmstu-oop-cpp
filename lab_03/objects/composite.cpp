#include "composite.h"

models_composite::models_composite(std::shared_ptr<model_obj> &component)
{
    this->objects.push_back(component);
}

models_composite::models_composite(vector<std::shared_ptr<model_obj>> vector)
{
    this->objects = vector;
}

bool models_composite::add(const std::shared_ptr<model_obj> &component)
{
    this->objects.push_back(component);
    return true;
}

bool models_composite::remove(const iterator<std::shared_ptr<model_obj>> &iterator)
{
    this->objects.remove(iterator);
    return true;
}

iterator<std::shared_ptr<model_obj>> models_composite::begin()
{
    return this->objects.begin();
}

iterator<std::shared_ptr<model_obj>> models_composite::end()
{
    return this->objects.end();
}

bool models_composite::is_composite() const
{
    return true;
}

size_t models_composite::size() const
{
    return this->objects.get_size();
}

void models_composite::draw(draw_manager &manager) const
{
    for (auto elem: objects)
    {
        elem->draw(manager);
    }
}

void models_composite::reform(const point &move, const point &scale, const point &turn)
{
    for (auto elem: objects)
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
