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

std::unique_ptr<model> model::clone()
{
    return std::unique_ptr<model>(new model(*this));
}

const vector<point> &model::get_points() const
{
    return this->points;
}

size_t model::points_count() const
{
    return this->points.get_size();
}

const vector<link> &model::get_links() const
{
    return this->links;
}

size_t model::links_count() const
{
    return this->links.get_size();
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
        point.move(dx, dy, dz);
    }
}

void model::scale(double &kx, double &ky, double &kz)
{
    for (auto point: points)
    {
        point.scale(kx, ky, kz);
    }
}

void model::turn(double &ox, double &oy, double &oz)
{
    for (auto point: points)
    {
        point.turn(ox, oy, oz);
    }
}
