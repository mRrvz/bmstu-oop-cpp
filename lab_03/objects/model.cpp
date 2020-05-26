#include "model.h"

#include "../managers/draw_manager.h"
#include "../visitor/visitor.h"

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

void model::move(const double dx, const double dy, const double dz)
{
    for (auto &point: points)
    {
        point.move(dx, dy, dz);
    }
}

void model::scale(const double kx, const double ky, const double kz)
{
    for (auto &point: points)
    {
        point.scale(kx, ky, kz);
    }
}

void model::turn(const double ox, const double oy, const double oz)
{
    for (auto &point: points)
    {
        point.turn(ox, oy, oz);
    }
}

void model::reform(const point &move_coeff, const point &scale_coeff, const point &turn_coeff)
{
    move(move_coeff.get_x(), move_coeff.get_y(), move_coeff.get_z());
    scale(scale_coeff.get_x(), scale_coeff.get_y(), scale_coeff.get_z());
    turn(turn_coeff.get_x(), turn_coeff.get_y(), turn_coeff.get_z());
}

void model::draw(draw_manager &_manager) const
{
    _manager.visit(*this);
}

void model::accept(std::shared_ptr<visitor> _visitor)
{
    _visitor->visit(*this);
}
