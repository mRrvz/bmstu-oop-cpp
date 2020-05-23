#include "camera.h"

double camera::get_x_pos()
{
    return x_pos;
}

double camera::get_y_pos()
{
    return y_pos;
}

void camera::move_x(const double &shift)
{
    this->y_pos += shift;
}

void camera::move_y(const double &shift)
{
    this->y_pos += shift;
}
