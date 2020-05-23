#ifndef BASE_COMMAND_H
#define BASE_COMMAND_H

#include <string>
#include "../facade/facade.h"
#include "../component/model.h"
#include "../component/camera.h"

class base_command
{
public:
    base_command() = default;
    virtual ~base_command() = default;
    virtual void execute(std::shared_ptr<facade> &facade) = 0;
};

class move_model : public base_command
{
public:
    move_model(const double &dx, const double &dy, const double &dz, const size_t &mnumb) :
        dx(dx), dy(dy), dz(dz), model_numb(mnumb) {};
    ~move_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point move(dx, dy, dz);
        point scale(1, 1, 1);
        point turn(0, 0, 0);

        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    double dx;
    double dy;
    double dz;

    size_t model_numb;
};

class scale_model : public base_command
{
public:
    scale_model(const double &kx, const double &ky, const double &kz, const size_t &mnumb) :
        kx(kx), ky(ky), kz(kz), model_numb(mnumb) {};
    ~scale_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point move(0, 0, 0);
        point scale(kx, ky, kz);
        point turn(0, 0, 0);

        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    double kx;
    double ky;
    double kz;

    size_t model_numb;
};

class turn_model : public base_command
{
public:
    turn_model(const double &ox, const double &oy, const double &oz, const size_t &mnumb) :
        ox(ox), oy(oy), oz(oz), model_numb(mnumb) {};
    ~turn_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        point move(0, 0, 0);
        point scale(1, 1, 1);
        point turn(ox, oy, oz);

        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    double ox;
    double oy;
    double oz;

    size_t model_numb;
};

class load_model : public base_command
{
public:
    load_model(const std::string &fname) : fname(fname) {};
    ~load_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->load_model(this->fname);
    }

private:
    std::string fname;
};

class add_model : public base_command
{
public:
    add_model(const model &model) : model_obj(model) {};
    ~add_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
    model model_obj;
};

class remove_model : public base_command
{
public:
    remove_model(const size_t &model_numb) : model_numb(model_numb) {};
    ~remove_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
    size_t model_numb;
};

class add_camera : public base_command
{
public:
    add_camera() = default;
    ~add_camera() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->add_camera();
    }
};

class remove_camera : public base_command
{
public:
    remove_camera(const size_t &camera_numb) : camera_numb(camera_numb) {};
    ~remove_camera() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
    size_t camera_numb;
};

class draw_scene : public base_command
{
public:
    draw_scene(std::shared_ptr<base_drawer> drawer) : _drawer(drawer) {};
    draw_scene() = default;
    ~draw_scene() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->draw_scene(_drawer);
    }

private:
    std::shared_ptr<base_drawer> _drawer;
};

class reform_model : public base_command
{
public:

    reform_model() = default;
    reform_model(const size_t &numb, const point &move, const point &scale, const point &turn) :
        model_numb(numb), move(move), scale(scale), turn(turn) {};
    ~reform_model() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override
    {
        facade->reform_model(model_numb, move, scale, turn);
    }

private:
    size_t model_numb;

    point move;
    point scale;
    point turn;
};

#endif
