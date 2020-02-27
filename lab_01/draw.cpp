#include "draw.h"

static point_t center_point(point_t &point, const plane_t &plane)
{
    point.x = point.x + plane.width / 2;
    point.y = point.y + plane.height / 2;

    return point;
}

static void draw_link(const link_t &link, const point_t *const points, const plane_t &plane)
{
    point_t pt1 = points[link.point_1];
    point_t pt2 = points[link.point_2];
    center_point(pt1, plane);
    center_point(pt2, plane);

    plane.scene->addLine(pt1.x, pt1.y, pt2.x, pt2.y);
}

void draw_links(const ldata_t &links, const pdata_t &points, const plane_t &plane)
{
    for (int i = 0; i < links.size; i++)
    {
        link_t current_link = links.array[i];
        draw_link(current_link, points.array, plane);
    }
}
