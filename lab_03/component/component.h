#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include "../vector/iterator.hpp"
#include "point.h"
//#include "../managers/draw_manager.h"

class draw_manager;

class component
{
public:
    component() = default;
    virtual ~component() = default;

    virtual bool add(const std::shared_ptr<component> &component) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<component>> &iterator) { return false; };

    virtual iterator<std::shared_ptr<component>>  begin() {} ;
    virtual iterator<std::shared_ptr<component>>  end()   {} ;

    virtual bool is_composite() const { return false; };

    virtual void draw(draw_manager &manager) const = 0;
    virtual void reform(const point &move, const point &scale, const point &turn) = 0;
};

class camera_obj
{
    camera_obj() = default;
    virtual ~camera_obj() = default;

    virtual bool add(const std::shared_ptr<camera_obj> &component) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<camera_obj>> &iterator) { return false; };

    virtual iterator<std::shared_ptr<camera_obj>>  begin() {} ;
    virtual iterator<std::shared_ptr<camera_obj>>  end()   {} ;

    virtual bool is_composite() const { return false; };

    virtual void reform(const point &new_pos) = 0;

private:
    point current_pos;
};


#endif
