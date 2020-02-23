#ifndef FIGURE_H
#define FIGURE_H

#include "ui_mainwindow.h"
#include "draw.h"
#include "points.h"
#include "links.h"
#include "errors.h"

struct figure
{
    pdata_t points;
    ldata_t links;
};

using figure_t = struct figure;
using fname_t = char[];

err_t load_figure(fname_t name, figure_t &figure);

void draw_figure(const figure_t figure, QGraphicsScene *scene);

void move_figure(pdata_t &points, const move_t coeffs);

void scale_figure(pdata_t &points, const scale_t coeffs);

void turn_figure(pdata_t &points, const turn coeffs);

void free_figure(const figure_t figure);

#endif
