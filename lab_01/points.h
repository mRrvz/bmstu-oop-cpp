#ifndef POINTS_H
#define POINTS_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "errors.h"

#define PI 3.1415

struct point
{
    double x;
    double y;
    double z;
};

using point_t = struct point;

struct points_data
{
    int size = 0;
    point_t *array = nullptr;
};

using pdata_t = struct points_data;

struct move
{
    double dx;
    double dy;
    double dz;
};

struct scale
{
    double kx;
    double ky;
    double kz;
};

struct turn
{
    double ox;
    double oy;
    double oz;
};

using move_t = struct move;
using scale_t = struct scale;
using turn_t = struct turn;

err_t handle_points(FILE *f, pdata_t &points);

void move_point(point_t &point, const move_t &coeffs);

void scale_point(point_t &point, const scale_t &coeffs);

void turn_xpoint(point_t &point, const double &angle);

void turn_ypoint(point_t &point, const double &angle);

void turn_zpoint(point_t &point, const double &angle);

void free_points(const pdata_t &points);

#endif
