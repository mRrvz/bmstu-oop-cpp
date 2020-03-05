#include "figure.h"

figure &init(void)
{
    static figure_t figure;
    figure.links.array = NULL;
    figure.links.size = 0;

    figure.points.array = NULL;
    figure.points.size = 0;

    return figure;
}

static err_t load_temp_figure(figure_t &temp_figure, FILE *f)
{
    err_t error_code = OK;
    if ((error_code = handle_points(temp_figure.points, f)))
    {
        return error_code;
    }

    if ((error_code = handle_links(temp_figure.links, f)))
    {
        free_points(temp_figure.points);
    }

    return error_code;
}

err_t load_figure(figure_t &figure, fname_t name)
{
    FILE *f = NULL;

    if ((f = fopen(name, "r")) == NULL)
    {
        return FILE_ERR;
    }

    err_t error_code = OK;
    figure_t temp_figure = init();
    error_code = load_temp_figure(temp_figure, f);
    fclose(f);

    if (error_code)
    {
        free_figure(temp_figure);
    }
    else
    {
        free_figure(figure);
        figure = temp_figure;
    }

    return error_code;
}

err_t draw_figure(const figure_t &figure,  const plane_t &plane)
{
    if (figure.links.array == NULL || figure.points.array == NULL)
    {
        return MEMORY_ERR;
    }

    plane.scene->clear();
    draw_links(figure.links, figure.points, plane);

    return OK;
}

static void move_points(pdata_t &points, const move_t &coeffs)
{
    for (int i = 0; i < points.size; i++)
    {
        move_point(points.array[i], coeffs);
    }
}

err_t move_figure(figure_t &figure, const move_t &coeffs)
{
    if (figure.points.array == NULL || figure.links.array == NULL)
    {
        return MEMORY_ERR;
    }

    move_points(figure.points, coeffs);

    return OK;
}

static void scale_points(pdata_t &points, const scale_t &coeffs)
{
    for (int i = 0; i < points.size; i++)
    {
        scale_point(points.array[i], coeffs);
    }
}

err_t scale_figure(figure_t &figure, const scale_t &coeffs)
{
    if (figure.points.array == NULL || figure.links.array == NULL)
    {
        return MEMORY_ERR;
    }

    scale_points(figure.points, coeffs);

    return OK;
}

static void turn_points(pdata_t &points, const turn &coeffs)
{
    for (int i = 0; i < points.size; i++)
    {
        turn_xpoint(points.array[i], coeffs.ox);
        turn_ypoint(points.array[i], coeffs.oy);
        turn_zpoint(points.array[i], coeffs.oz);
    }
}

err_t turn_figure(figure_t &figure, const turn &coeffs)
{
    if (figure.points.array == NULL || figure.links.array == NULL)
    {
        return MEMORY_ERR;
    }

    turn_points(figure.points, coeffs);

    return OK;
}

void free_figure(const figure_t &figure)
{
    free_points(figure.points);
    free_links(figure.links);
}
