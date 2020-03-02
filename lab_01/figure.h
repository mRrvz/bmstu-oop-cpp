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
using fname_t = const char *;

figure &init(void);

err_t load_figure(figure_t &figure, fname_t name);

err_t draw_figure(const figure_t &figure,  const plane_t &plane);

err_t move_figure(figure_t &figure, const move_t &coeffs);

err_t scale_figure(figure_t &figure, const scale_t &coeffs);

err_t turn_figure(figure_t &figure, const turn &coeffs);

void free_figure(const figure_t &figure);

#endif
