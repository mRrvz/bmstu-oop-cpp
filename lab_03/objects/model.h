#ifndef MODEL_H
#define MODEL_H

#include <memory>

#include "../vector/vector.hpp"
#include "../vector/iterator.hpp"

#include "component.h"
#include "link.h"
#include "point.h"

class model : public model_obj
{
public:
    model() = default;
    model(const vector<point> &points, const vector<link> &links) : points(points), links(links) {};

    model(const model &model);
    model &operator=(const model& model);

    model(model &&model);
    model &operator=(model&& model);

    ~model() = default;

    std::unique_ptr<model> clone();

    const vector<point> &get_points() const;
    size_t points_count() const;

    const vector<link>  &get_links() const;
    size_t links_count() const;

    void add_point(const point &point);
    void add_link (const link &link);

    void move (const double dx, const double dy, const double dz);
    void scale(const double kx, const double ky, const double kz);
    void turn (const double ox, const double oy, const double oz);

    virtual void draw(draw_manager &manager) const override;
    virtual void reform(const point &move, const point &scale, const point &turn) override;

private:
    vector<point> points;
    vector<link> links;
};

#endif
