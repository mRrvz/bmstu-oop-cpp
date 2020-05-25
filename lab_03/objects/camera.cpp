#include "camera.h"
#include "../visitor/visitor.h"

point camera::get_pos()
{
    return current_pos;
}

void camera::move_x(const double &shift)
{
    this->current_pos.set_x(this->current_pos.get_x() + shift);
}

void camera::move_y(const double &shift)
{
    this->current_pos.set_y(this->current_pos.get_y() + shift);
}

void camera::move_z(const double &shift)
{
    this->current_pos.set_z(this->current_pos.get_z() + shift);
}

void camera::reform(const point &new_pos)
{
    this->move_x(new_pos.get_x());
    this->move_y(new_pos.get_y());
}

void camera::accept(std::shared_ptr<visitor> _visitor)
{
    _visitor->visit(*this);
}
