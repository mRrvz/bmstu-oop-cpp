#ifndef CAMERA_H
#define CAMERA_H

#include "component.h"

class camera : public component
{
public:
    camera();
    ~camera() = default;

    //virtual void operation() const { };

    //virtual bool is_visible() override;

    void move (double &dx, double &dy, double& dz);
    void scale(double &kx, double &ky, double &kz);
    void turn (double &ox, double &oy, double &oz);
};

#endif
