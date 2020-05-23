#include "draw_manager.h"


void draw_manager::set_drawer(std::shared_ptr<base_drawer> drawer_)
{
    this->_drawer = drawer_;
}

void draw_manager::set_cam(std::shared_ptr<camera> new_cam)
{
    this->current_cam = new_cam;
}

void draw_manager::draw_model(const model &model)
{
    const vector<point> points = model.get_points();

    for (auto link: model.get_links())
    {
        point pt1 = points.at(link.get_fst());
        point pt2 = points.at(link.get_snd());

        this->_drawer->draw_line(pt1, pt2);
    }
}
