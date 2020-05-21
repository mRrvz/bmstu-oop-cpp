#include "scene.h"

scene::scene()
{

}

void scene::load_file(QString &filename)
{


}

void scene::draw()
{

}


void scene::add_model(const std::shared_ptr<component> &model)
{
    //this->objects.add(model);
}

void scene::remove_model(const size_t &index)
{
    //this->objects.remove(index);
}

void scene::add_camera(const std::shared_ptr<component> &camera)
{
    // ?
}

void scene::remove_camera(const size_t &index)
{

}

std::shared_ptr<component> scene::get_model(const size_t &index)
{

}

std::shared_ptr<component> scene::get_camera(const size_t &index)
{

}

void scene::set_scene(QGraphicsScene *scene)
{
    this->_scene = scene;
}

QGraphicsScene *scene::get_scene()
{
    return _scene;
}
