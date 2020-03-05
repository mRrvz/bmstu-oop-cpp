#include "draw.h"

static void draw_link(const link_t &link, const point_t *const points, const plane_t &plane)
{
    point_t pt1 = points[link.point_1];
    point_t pt2 = points[link.point_2];

    plane.scene->addLine(
        pt1.x + plane.width / 2,
        pt1.y + plane.height / 2,
        pt2.x + plane.width / 2,
        pt2.y + plane.height / 2
   );
}

void draw_links(const ldata_t &links, const pdata_t &points, const plane_t &plane)
{
    for (int i = 0; i < links.size; i++)
    {
        draw_link(links.array[i], points.array, plane);
    }
}
