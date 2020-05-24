#include "scene.h"

scene::scene()
{
    this->cams = std::shared_ptr<cams_composite>(new cams_composite);
    this->models = std::shared_ptr<composite>(new composite);
}

void scene::add_model(std::shared_ptr<component> model)
{
    this->models->add(model);
}

void scene::remove_model(const iterator<std::shared_ptr<component>> &iterator)
{
    this->models->remove(iterator);
}

void scene::add_camera(const std::shared_ptr<camera_obj> &camera)
{
    this->cams->add(camera);
}

void scene::remove_camera(const iterator<std::shared_ptr<camera_obj>> &iterator)
{
    this->cams->remove(iterator);
}

iterator<std::shared_ptr<component>> scene::models_begin() const
{
    return this->models->begin();
}

iterator<std::shared_ptr<component>> scene::models_end() const
{
    return this->models->end();
}

iterator<std::shared_ptr<camera_obj>> scene::cams_begin() const
{
    return this->cams->begin();
}

iterator<std::shared_ptr<camera_obj>> scene::cams_end() const
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
    return this->models;
}

std::shared_ptr<cams_composite> scene::get_cams() const
{
    return this->cams;
}

