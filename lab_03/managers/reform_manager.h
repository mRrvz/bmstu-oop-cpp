#ifndef REFORM_MANAGER_H
#define REFORM_MANAGER_H

#include "../objects/component.h"

class reform_manager
{
public:
    reform_manager() = default;
    ~reform_manager() = default;

    void reform_model(std::shared_ptr<model_obj> _component, const point &move, const point &scale, const point &turn);
    void reform_camera(std::shared_ptr<camera_obj> cam, const point &new_pos);

    void move_model(std::shared_ptr<model_obj> _component, const double &dx, const double &dy, const double &dz);
    void scale_model(std::shared_ptr<model_obj> _component, const double &kx, const double &ky, const double &kz);
    void turn_model(std::shared_ptr<model_obj> _component, const double &ox, const double &oy, const double &oz);
};

#endif
