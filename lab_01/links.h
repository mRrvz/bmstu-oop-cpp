#ifndef LINKS_H
#define LINKS_H

#include <stdio.h>
#include <stdlib.h>

#include "ui_mainwindow.h"
#include "errors.h"
#include "points.h"

struct link
{
    int point_1;
    int point_2;
};

using link_t = struct link;

struct links_data
{
    int size = 0;
    link_t *array = nullptr;
};

using ldata_t = struct links_data;

err_t handle_links(FILE *f, ldata_t &links);

void draw_links(point_t pt1, point_t pt2, QGraphicsScene *scene);

void free_links(ldata_t links);

#endif 
