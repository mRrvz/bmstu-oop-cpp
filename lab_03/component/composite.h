#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"
#include "model.h"

class composite : public component
{
public:

    friend class scene;

    composite() = default;
    composite(component &component);
    composite(vector<component> vector);

    //virtual void operatrion() const { };
    virtual bool add(const component &component);
    virtual bool remove(const iterator<component> &iterator);
    virtual iterator<component> begin();
    virtual iterator<component> end();
    virtual bool is_composite() const;

private:
    vector<component> components;

};

#endif
