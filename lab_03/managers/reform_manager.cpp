#include "reform_manager.h"
#include <QDebug>

void reform_manager::reform_camera(std::shared_ptr<camera_obj> cam, const point &new_pos)
{
    cam->reform(new_pos);
}

void reform_manager::reform_model(std::shared_ptr<model_obj> _model, const point &move, const point &scale, const point &turn)
{
    _model->reform(move, scale, turn);
}

void reform_manager::move_model(std::shared_ptr<model_obj> _model, const double &dx, const double &dy, const double &dz)
{
    point move(dx, dy, dz);
    point scale(1, 1, 1);
    point turn(0, 0, 0);

    _model->reform(move, scale, turn);
}

void reform_manager::scale_model(std::shared_ptr<model_obj> _model, const double &kx, const double &ky, const double &kz)
{
    point move(0, 0, 0);
    point scale(kx, ky, kz);
    point turn(0, 0, 0);

    _model->reform(move, scale, turn);
}

void reform_manager::turn_model(std::shared_ptr<model_obj> _model, const double &ox, const double &oy, const double &oz)
{
    point move(0, 0, 0);
    point scale(1, 1, 1);
    point turn(ox, oy, oz);

    _model->reform(move, scale, turn);
}

