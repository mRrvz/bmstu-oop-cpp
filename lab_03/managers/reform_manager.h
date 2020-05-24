#ifndef REFORM_MANAGER_H
#define REFORM_MANAGER_H

#include "../component/component.h"

class reform_manager
{
public:
    reform_manager() = default;
    ~reform_manager() = default;

    void reform_component(std::shared_ptr<component> _component, const point &move, const point &scale, const point &turn);
    void reform_camera(std::shared_ptr<camera_obj> cam, const point &new_pos);

    void move_component(std::shared_ptr<component> _component, const double &dx, const double &dy, const double &dz);
    void scale_component(std::shared_ptr<component> _component, const double &kx, const double &ky, const double &kz);
    void turn_component(std::shared_ptr<component> _component, const double &ox, const double &oy, const double &oz);
};

#endif
