#include "load_manager.h"

std::shared_ptr<model> load_manager::load_model(std::string &fname)
{
    this->loader.fopen(fname);
    std::shared_ptr<model> model(loader.load_model(this->builder));
    this->loader.fclose();

    return model;
}
