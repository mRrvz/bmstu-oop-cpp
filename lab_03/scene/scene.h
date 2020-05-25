#ifndef SCENE_H
#define SCENE_H

#include "ui_mainwindow.h"
#include "../objects/composite.h"
#include "../objects/camera.h"

class scene
{
public:
    scene();
    ~scene() = default;

    void add_model(std::shared_ptr<model_obj> model);
    void remove_model(const iterator<std::shared_ptr<model_obj>> &iterator);

    void add_camera(const std::shared_ptr<camera_obj> &camera);
    void remove_camera(const iterator<std::shared_ptr<camera_obj>> &iterator);

    iterator<std::shared_ptr<model_obj>> models_begin() const;
    iterator<std::shared_ptr<model_obj>> models_end() const;

    iterator<std::shared_ptr<camera_obj>> cams_begin() const;
    iterator<std::shared_ptr<camera_obj>> cams_end() const;

    std::shared_ptr<models_composite> get_models() const;
    std::shared_ptr<cams_composite> get_cams() const;

    size_t models_count() const;
    size_t cams_count() const;

protected:
    std::shared_ptr<models_composite> models;
    std::shared_ptr<cams_composite> cams;
};

#endif
