#include "reform_manager.h"
#include <QDebug>

void reform_manager::reform_camera(std::shared_ptr<component> _component, const double &x_shift, const double &y_shift)
{

}

void reform_manager::reform_component(std::shared_ptr<component> _component, const point &move, const point &scale, const point &turn)
{
    _component->reform(move, scale, turn);
}

void reform_manager::move_component(std::shared_ptr<component> _component, const double &dx, const double &dy, const double &dz)
{
    point move(dx, dy, dz);
    point scale(1, 1, 1);
    point turn(0, 0, 0);

    _component->reform(move, scale, turn);
}

void reform_manager::scale_component(std::shared_ptr<component> _component, const double &kx, const double &ky, const double &kz)
{
    point move(0, 0, 0);
    point scale(kx, ky, kz);
    point turn(0, 0, 0);

    _component->reform(move, scale, turn);
}

void reform_manager::turn_component(std::shared_ptr<component> _component, const double &ox, const double &oy, const double &oz)
{
    point move(0, 0, 0);
    point scale(1, 1, 1);
    point turn(ox, oy, oz);

    _component->reform(move, scale, turn);
}

