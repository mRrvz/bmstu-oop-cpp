#ifndef SCENE_H
#define SCENE_H

#include "ui_mainwindow.h"
#include "component/composite.h"

class scene
{
public:
    scene();

    void load_file(QString &filename);
    void draw();

    void add_model(const std::shared_ptr<component> &model);
    void remove_model(const size_t &index);

    void add_camera(const std::shared_ptr<component> &camera);
    void remove_camera(const size_t &index);

    std::shared_ptr<component> get_model(const size_t &index);
    std::shared_ptr<component> get_camera(const size_t &index);

    void set_scene(QGraphicsScene *_scene);
    QGraphicsScene *get_scene();
    //void next_camera();


protected:
    QGraphicsScene *_scene;
    composite objects;
    // current camera?
};

#endif // SCENE_H
