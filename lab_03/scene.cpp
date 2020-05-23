#include "scene.h"

scene::scene()
{
    this->cams = std::shared_ptr<composite>(new composite);
    this->models = std::shared_ptr<composite>(new composite);
}

void scene::add_model(std::shared_ptr<component> model)
{
    this->models->add(model);
    //this->objects.add(model);
}

void scene::remove_model(const iterator<std::shared_ptr<component>> &iterator)
{
    this->models->remove(iterator);
    //this->objects.remove(index);
}

void scene::add_camera(const std::shared_ptr<component> &camera)
{
    this->cams->add(camera);
}

void scene::remove_camera(const iterator<std::shared_ptr<component>> &iterator)
{
    this->cams->remove(iterator);
}

/*
std::shared_ptr<component> scene::get_model(const iterator<std::shared_ptr<component>> &iterator) const
{
    this->models.get(index);
}

std::shared_ptr<component> scene::get_camera(const iterator<component> &iterator) const
{

}
*/

iterator<std::shared_ptr<component>> scene::models_begin() const
{
    return this->models->begin();
}

iterator<std::shared_ptr<component>> scene::models_end() const
{
    return this->models->end();
}

iterator<std::shared_ptr<component>> scene::cams_begin() const
{
    return this->cams->begin();
}

iterator<std::shared_ptr<component>> scene::cams_end() const
{
    return this->cams->end();
}

size_t scene::models_count() const
{
    return this->models->size();
}

size_t scene::cams_count() const
{
    return this->cams->size();
}

std::shared_ptr<composite> scene::get_models() const
{
    return models;
}

std::shared_ptr<composite> scene::get_cams() const
{
    return cams;
}

