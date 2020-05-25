#ifndef COMPOSITE_H
#define COMPOSITE_H

#include "component.h"
#include "model.h"

class models_composite : public model_obj
{
public:
    models_composite() = default;
    models_composite(std::shared_ptr<model_obj> &component);
    models_composite(vector<std::shared_ptr<model_obj>> vector);

    size_t size() const;

    virtual bool add(const std::shared_ptr<model_obj> &component) override;
    virtual bool remove(const iterator<std::shared_ptr<model_obj>> &iterator) override;

    virtual iterator<std::shared_ptr<model_obj>> begin() override;
    virtual iterator<std::shared_ptr<model_obj>> end() override;

    virtual bool is_composite() const override;
    virtual void draw(draw_manager &manager) const override;
    virtual void reform(const point &move, const point &scale, const point &turn) override;
    virtual void accept(std::shared_ptr<visitor> visitor) override;

private:
    vector<std::shared_ptr<model_obj>> objects;

};

class cams_composite : public camera_obj
{
public:
    cams_composite() = default;
    cams_composite(std::shared_ptr<camera_obj> &obj);
    cams_composite(vector<std::shared_ptr<camera_obj>> vector);

    size_t size() const;

    virtual bool add(const std::shared_ptr<camera_obj> &component) override;
    virtual bool remove(const iterator<std::shared_ptr<camera_obj>> &iterator) override;

    virtual iterator<std::shared_ptr<camera_obj>> begin() override;
    virtual iterator<std::shared_ptr<camera_obj>> end() override;

    virtual bool is_composite() const override;
    virtual void reform(const point &move) override;
    virtual void accept(std::shared_ptr<visitor> visitor) override;

private:
    vector<std::shared_ptr<camera_obj>> objects;
};

#endif
