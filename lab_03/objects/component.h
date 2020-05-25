#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>

//#include "../visitor/visitor.h"
#include "../vector/iterator.hpp"
#include "point.h"

class visitor;
class draw_manager;

class model_obj
{
public:
    model_obj() = default;
    virtual ~model_obj() = default;

    virtual bool add(const std::shared_ptr<model_obj>&) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<model_obj>>&) { return false; };

    virtual iterator<std::shared_ptr<model_obj>> begin() {};
    virtual iterator<std::shared_ptr<model_obj>> end()   {};

    virtual bool is_composite() const { return false; };

    virtual void draw(draw_manager &manager) const = 0;
    virtual void accept(std::shared_ptr<visitor> visitor) = 0;
    virtual void reform(const point &move, const point &scale, const point &turn) = 0;
};

class camera_obj
{
public:
    camera_obj() = default;
    virtual ~camera_obj() = default;

    virtual bool add(const std::shared_ptr<camera_obj>&) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<camera_obj>>&) { return false; };

    virtual iterator<std::shared_ptr<camera_obj>> begin() {};
    virtual iterator<std::shared_ptr<camera_obj>> end()   {};

    virtual bool is_composite() const { return false; };

    virtual void reform(const point &new_pos) = 0;
    virtual void accept(std::shared_ptr<visitor> visitor) = 0;

private:
    point current_pos;
};


#endif
