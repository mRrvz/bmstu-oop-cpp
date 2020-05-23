#ifndef MODEL_H
#define MODEL_H

#include <memory>

#include "../vector/vector.hpp"
#include "../vector/iterator.hpp"

#include "component.h"
#include "link.h"
#include "point.h"

class model : public component
{
public:
    model() = default;
    model(const vector<point> &points, const vector<link> &links) : points(points), links(links) {};

    model(const model &model);
    model &operator=(const model& model);

    model(model &&model);
    model &operator=(model&& model);

    ~model() = default;

    //virtual void operation() const { };

    std::unique_ptr<model> clone();

    //virtual bool is_visible() override;

    const vector<point> &get_points() const;
    size_t points_count() const;

    const vector<link>  &get_links() const;
    size_t links_count() const;

    void add_point(const point &point);
    void add_link (const link &link);

    void move (double &dx, double &dy, double& dz);
    void scale(double &kx, double &ky, double &kz);
    void turn (double &ox, double &oy, double &oz);

private:
    vector<point> points;
    vector<link> links;
};

#endif
