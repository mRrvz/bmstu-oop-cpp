#include "facade.h"

void facade::load_model(std::string fname)
{
    std::shared_ptr<model> model = this->_load_manager.load_model(fname);
    this->_scene_manager.get_scene()->add_model(model);
}

void facade::add_model(const std::shared_ptr<model_obj> &model)
{
    this->_scene_manager.get_scene()->add_model(model);
}

void facade::remove_model(const size_t &index)
{
    this->_scene_manager.get_scene()->remove_model(
                _scene_manager.get_scene()->models_end() + (index - 1)
    );
}

void facade::add_camera(const point &cam_pos)
{
    std::shared_ptr<camera_obj> cam(new camera);
    cam->reform(cam_pos);

    this->_scene_manager.get_scene()->add_camera(cam);
    this->_scene_manager.set_cam(_scene_manager.get_scene()->cams_count());
}

void facade::remove_camera(const size_t &index)
{
    this->_scene_manager.get_scene()->remove_camera(
                _scene_manager.get_scene()->cams_end() + (index - 1)
    );
}

void facade::reform_model(const size_t &model_numb, const point &move, const point &scale, const point &turn)
{
    auto model = *(_scene_manager.get_scene()->models_begin() + (model_numb - 1));
    _reform_manager.reform_model(model, move, scale, turn);
}

void facade::reform_models(const point &move, const point &scale, const point &turn)
{
    _scene_manager.get_scene()->get_models()->reform(move, scale, turn);
}

void facade::set_camera(const size_t &camera_numb)
{
    _scene_manager.set_cam(camera_numb);
}

void facade::draw_scene(std::shared_ptr<base_drawer> _drawer)
{
    _drawer->clear_scene();
    _draw_manager.set_drawer(_drawer);
    _draw_manager.set_cam(std::dynamic_pointer_cast<camera> (_scene_manager.get_cam()));
    _scene_manager.get_scene()->get_models()->draw(_draw_manager);
}

void facade::reform_cam(const size_t &cam_numb, const point &shift)
{
    auto camera = *(_scene_manager.get_scene()->cams_begin() + (cam_numb - 1));
    _reform_manager.reform_camera(camera, shift);
}

void facade::reform_cams(const point &shift)
{
    _scene_manager.get_scene()->get_cams()->reform(shift);
}

size_t facade::cams_count()
{
    return _scene_manager.get_scene()->cams_count();
}

size_t facade::models_count()
{
    return _scene_manager.get_scene()->models_count();
}
