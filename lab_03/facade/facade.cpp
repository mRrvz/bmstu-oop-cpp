#include "facade.h"


void facade::load_model(std::string fname)
{
    std::shared_ptr<model> model = this->_load_manager.load_model(fname);
    this->_scene_manager.get_scene()->add_model(model);
    //qDebug() << _scene_manager.get_scene()->models_count() << _scene_manager.get_scene()->cams_count();
}

/*
void facade::load_view(const base_loader &loader)
{
    //this->_viewer.add_view(this->load.load_model(loader));
}

void facade::remove_view(const size_t &index)
{
    //this->_viewer.remove_view(index);
}
*/

void facade::remove_model(const size_t &index)
{

}

void facade::add_camera()
{

}

void facade::remove_camera(const size_t &index)
{

}
