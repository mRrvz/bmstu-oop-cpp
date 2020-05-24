#include "scene_manager.h"

scene_manager::scene_manager()
{
    this->_scene = std::shared_ptr<scene>(new scene);
}

std::shared_ptr<scene> scene_manager::get_scene() const
{
    return this->_scene;
}

std::shared_ptr<camera_obj> scene_manager::get_cam() const
{
    return this->current_cam;
}

void scene_manager::set_scene(std::shared_ptr<scene> scene_)
{
    this->_scene = scene_;
}

void scene_manager::set_cam(const size_t &number)
{
    auto _camera = *(_scene->cams_begin() + (number - 1));
    this->current_cam = _camera;
}

void scene_manager::next_cam()
{

}
