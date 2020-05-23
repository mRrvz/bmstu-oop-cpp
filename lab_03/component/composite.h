#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"
#include "model.h"

class composite : public component
{
public:

    friend class scene;

    composite() = default;
    composite(std::shared_ptr<component> &component);
    composite(vector<std::shared_ptr<component>> vector);

    size_t size() const;

    virtual bool add(const std::shared_ptr<component> &component);
    virtual bool remove(const iterator<std::shared_ptr<component>> &iterator);

    virtual iterator<std::shared_ptr<component>> begin();
    virtual iterator<std::shared_ptr<component>> end();

    virtual bool is_composite() const;

    virtual void draw(draw_manager &manager) const override;
    virtual void reform(const point &move, const point &scale, const point &turn) override;

private:
    vector<std::shared_ptr<component>> components;

};

#endif
