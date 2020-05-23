#ifndef COMPONENT_H
#define COMPONENT_H

#include <memory>
#include "../vector/iterator.hpp"

class component
{
public:
    component() = default;
    virtual ~component() = default;

    /*
    virtual void move() const = 0;
    virtual void scale() const = 0;
    virtual void turn() const = 0;
    */

    //virtual void operation() const = 0;

    virtual bool add(const std::shared_ptr<component> &component) { return false; };
    virtual bool remove(const iterator<std::shared_ptr<component>> &iterator) { return false; };
    virtual iterator<std::shared_ptr<component>>  begin() {};
    virtual iterator<std::shared_ptr<component>>  end()   {} ;
    virtual bool is_composite() const { return false; };
    //virtual bool is_visible() = 0;
};

#endif // OBJECT_H
