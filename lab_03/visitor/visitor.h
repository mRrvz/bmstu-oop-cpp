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

    virtual void visit(const camera &cam) = 0;
    virtual void visit(const model &model) = 0;
    virtual void visit(const cams_composite &composite) = 0;
    virtual void visit(const models_composite &composite) = 0;
};

#endif
