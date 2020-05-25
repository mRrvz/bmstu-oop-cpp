#ifndef VISITOR_H
#define VISITOR_H

#include "../objects/camera.h"
#include "../objects/model.h"
#include "../objects/composite.h"

class visitor
{
public:
    visitor() = default;
    ~visitor() = default;

    virtual void visit(camera &cam) = 0;
    virtual void visit(model &model) = 0;
    virtual void visit(cams_composite &composite) = 0;
    virtual void visit(models_composite &composite) = 0;
};

#endif
