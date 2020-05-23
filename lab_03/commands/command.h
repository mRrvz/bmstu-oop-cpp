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
        qDebug() << "move command\n" ;
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
        qDebug() << "scale command\n" ;
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
        qDebug() << "turn command\n";
    }

private:
    double ox;
    double oy;
    double oz;

    size_t model_numb;
};

class turn_model_ox : public base_command
{
public:
    turn_model_ox(const double &ox, const size_t &mnumb) : ox(ox), model_numb(mnumb) {};
    ~turn_model_ox() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
    double ox;

    size_t model_numb;
};

class turn_model_oy : public base_command
{
public:
    turn_model_oy(const double &oy, const size_t &mnumb) : oy(oy), model_numb(mnumb) {};
    ~turn_model_oy() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
    double oy;

    size_t model_numb;
};

class turn_model_oz : public base_command
{
public:
    turn_model_oz(const double &oz, const size_t &mnumb) : oz(oz), model_numb(mnumb) {};
    ~turn_model_oz() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
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
        if (facade == nullptr)
        {
            qDebug() << "nullptr";
        }

        facade->load_model(this->fname);
        //facade.load.load_model();
        qDebug() << "load command\n";
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
    add_camera(const camera &camera) : camera_obj(camera) {};
    ~add_camera() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:
    camera camera_obj;
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
    draw_scene();
    ~draw_scene() = default;

    virtual void execute(std::shared_ptr<facade> &facade) override;

private:

};

#endif
