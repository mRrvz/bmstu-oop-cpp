#ifndef DRAW_H
#define DRAW_H

#include "ui_mainwindow.h"
#include "points.h"
#include "links.h"

struct plane
{
    QGraphicsScene *scene;
    double width;
    double height;
};

using plane_t = struct plane;

void draw_links(const ldata_t &links, const pdata_t &points, const plane_t &plane);

#endif
