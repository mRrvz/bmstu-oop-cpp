#ifndef DRAWER_H
#define DRAWER_H

#include "ui_mainwindow.h"
#include "component/point.h"

class base_drawer
{
public:
    base_drawer() = default;
    virtual ~base_drawer() = default;
    virtual void draw_line(const point &point1, const point &point2) = 0;
};

class drawer : public base_drawer
{
public:
    drawer(QGraphicsScene *_scene) : scene(_scene) {};
    drawer(const drawer &_drawer);
    virtual void draw_line(const point &point1, const point &point2) override;

private:
    QGraphicsScene *scene;
};

#endif
