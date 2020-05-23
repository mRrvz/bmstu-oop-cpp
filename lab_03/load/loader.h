#ifndef LOADER_H
#define LOADER_H

#include <string>
#include <fstream>

#include "builder.h"
#include "../component/model.h"

class base_loader
{
public:
    base_loader() = default;
    virtual ~base_loader() = default;

    virtual std::shared_ptr<model> load_model(base_builder &builder) = 0;
    virtual void fopen(std::string &fname) = 0;
    virtual void fclose() = 0;
};

class model_loader : public base_loader
{
public:
    model_loader() : file(nullptr) {};
    ~model_loader() = default;

    virtual std::shared_ptr<model> load_model(base_builder &builder) override;
    virtual void fopen(std::string &fname) override;
    virtual void fclose() override;

private:
    std::fstream file;
};

#endif
