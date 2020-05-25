#ifndef CAMERA_H
#define CAMERA_H

#include "component.h"

class camera : public camera_obj
{
public:
    camera() = default;
    camera(const point &pos) : current_pos(pos) {};
    ~camera() = default;

    virtual void reform(const point &new_pos) override;
    virtual void accept(std::shared_ptr<visitor> visitor) override;
    point get_pos();

    void move_x(const double &shift);
    void move_y(const double &shift);
    void move_z(const double &shift);

private:
    point current_pos;
};

#endif
