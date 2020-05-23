#ifndef SCENE_H
#define SCENE_H

#include "ui_mainwindow.h"
#include "component/composite.h"
#include "component/camera.h"

class scene
{
public:
    scene();
    ~scene() = default;

    void add_model(std::shared_ptr<component> model);
    void remove_model(const iterator<std::shared_ptr<component>> &iterator);

    void add_camera(const std::shared_ptr<component> &camera);
    void remove_camera(const iterator<std::shared_ptr<component>> &iterator);

    iterator<std::shared_ptr<component>> models_begin() const;
    iterator<std::shared_ptr<component>> models_end() const;

    iterator<std::shared_ptr<component>> cams_begin() const;
    iterator<std::shared_ptr<component>> cams_end() const;

    std::shared_ptr<composite> get_models() const;
    std::shared_ptr<composite> get_cams() const;

    //std::shared_ptr<camera> get_cam(iterator<std::shared_ptr<component>> iterator) const

    size_t models_count() const;
    size_t cams_count() const;

protected:
    std::shared_ptr<composite> models;
    std::shared_ptr<composite> cams;
};

#endif
