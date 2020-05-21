#ifndef BUILDER_H
#define BUILDER_H

#include <memory>
#include "component/model.h"

class base_builder
{
public:
    base_builder() = default;
    ~base_builder() = default;
};

class model_builder : public base_builder
{
public:
    model_builder();
    ~model_builder() = default;

private:
    std::shared_ptr<model> model_ptr;

};

#endif // BUILDER_H
