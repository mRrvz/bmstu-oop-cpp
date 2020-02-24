#include "figure.h"

err_t load_figure(fname_t name, figure_t &figure)
{
    FILE *f = nullptr;
    figure_t temp_figure;
    err_t error_code;

    if ((f = fopen(name, "r")) == nullptr)
    {
        return FILE_ERR;
    }

    if ((error_code = handle_points(f, temp_figure.points)))
    {
        fclose(f);
        return error_code;
    }

    if ((error_code = handle_links(f, temp_figure.links)))
    {
        fclose(f);
        free_points(figure.points);
        return error_code;
    }

    figure = temp_figure;
    fclose(f);

    return OK;
}

void draw_figure(const figure_t &figure, QGraphicsScene *scene)
{
    plane_t plane = { scene, scene->width(), scene->height() };

    scene->clear();
    draw_links(figure.links, figure.points, plane);
}

void move_figure(pdata_t &points, const move_t &coeffs)
{
    for (int i = 0; i < points.size; i++)
    {
        move_point(points.array[i], coeffs);
    }
}

void scale_figure(pdata_t &points, const scale_t &coeffs)
{
    for (int i = 0; i < points.size; i++)
    {
        scale_point(points.array[i], coeffs);
    }
}

void turn_figure(pdata_t &points, const turn &coeffs)
{
    for (int i = 0; i < points.size; i++)
    {
        turn_xpoint(points.array[i], coeffs.ox);
        turn_ypoint(points.array[i], coeffs.oy);
        turn_zpoint(points.array[i], coeffs.oz);
    }
}

void free_figure(const figure_t &figure)
{
    free_points(figure.points);
    free_links(figure.links);
}
