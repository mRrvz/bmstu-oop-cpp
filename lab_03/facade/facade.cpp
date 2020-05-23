#include "facade.h"

void facade::load_model(std::string fname)
{
    std::shared_ptr<model> model = this->_load_manager.load_model(fname);
    this->_scene_manager.get_scene()->add_model(model);
}

void facade::remove_model(const size_t &index)
{

}

void facade::add_camera()
{
    /*
    std::shared_ptr<camera> cam(new camera);
    this->_scene_manager.get_scene()->add_camera(cam);
    */
}

void facade::remove_camera(const size_t &index)
{

}

void facade::reform_model(const size_t &model_numb, const point &move, const point &scale, const point &turn)
{
    auto model = *(_scene_manager.get_scene()->models_begin() + (model_numb - 1));
    _reform_manager.reform_component(model, move, scale, turn);
}

void facade::reform_models(const point &move, const point &scale, const point &turn)
{
    _scene_manager.get_scene()->get_models()->reform(move, scale, turn);
}

void facade::draw_scene(std::shared_ptr<base_drawer> _drawer)
{
    _drawer->clear_scene();
    _draw_manager.set_drawer(_drawer);
    _draw_manager.set_cam(_scene_manager.get_cam());
    _scene_manager.get_scene()->get_models()->draw(_draw_manager);
}

void facade::reform_cam(const size_t &cam_numb, const double &x_shift, const double &y_shift)
{
    auto camera = *(_scene_manager.get_scene()->cams_begin() + (cam_numb - 1));
}

void facade::reform_cams(const double &x_shift, const double &y_shift)
{

}
