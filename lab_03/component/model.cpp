#include "model.h"

model::model(const model &model)
{
    this->points = model.points;
    this->links = model.links;
}

model &model::operator=(const model& model)
{
    this->points = model.points;
    this->links = model.links;

    return *this;
}

model::model(model &&model)
{
    this->points = model.points;
    this->links = model.links;
    model.~model();
}

model &model::operator=(model &&model)
{
    this->points = model.points;
    this->links = model.links;
    model.~model();

    return *this;
}

const vector<point> &model::get_points() const
{
    return this->points;
}

const vector<link> &model::get_links() const
{
    return this->links;
}

void model::add_point(const point &edge)
{
    this->points.push_back(edge);
}

void model::add_link(const link &link)
{
    this->links.push_back(link);
}

void model::move(double &dx, double &dy, double& dz)
{
    for (auto point: points)
    {
        //points.
    }
}

void model::scale(double &kx, double &ky, double &kz)
{
    for (auto point: points)
    {
        //
    }
}

void model::turn(double &ox, double &oy, double &oz)
{
    for (auto point: points)
    {

    }
}
