#ifndef LOAD_MANAGER_H
#define LOAD_MANAGER_H

#include "../load/builder.h"
#include "../load/loader.h"

class load_manager
{
public:
    load_manager() = default;
    ~load_manager() = default;

    std::shared_ptr<model> load_model(std::string &fname);

private:
    model_builder builder;
    model_loader loader;
};

#endif
