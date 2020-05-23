#ifndef CAMERA_H
#define CAMERA_H

#include "component.h"

class camera : public camera_obj
{
public:
    camera() = default;
    camera(const double &x_pos, const double &y_pos) : x_pos(x_pos), y_pos(y_pos) {};
    ~camera() = default;

    double get_x_pos();
    double get_y_pos();

    void move_x(const double &shift); // to virtual
    void move_y(const double &shift); // to virtual

    virtual void draw(draw_manager &manager) const override
    {

    }

    virtual void reform(const point &move, const point &scale, const point &turn) override
    {

    }

private:
    double x_pos;
    double y_pos;
};

#endif
