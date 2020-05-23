#include "drawer.h"

drawer::drawer(const drawer &_drawer)
{
    this->scene = _drawer.scene;
}

void drawer::draw_line(const point &point1, const point &point2)
{
    this->scene->addLine(point1.get_x(), point1.get_y(), point2.get_x(), point2.get_y());
}
