#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>

#include "../managers/load_manager.h"
#include "../managers/draw_manager.h"
#include "../managers/scene_manager.h"

class base_mediator
{
public:
    //virtual void notify(std::string event) const = 0;
    //mediator();
};

class mediator : public base_mediator
{
public:
    mediator() = default;
    ~mediator() = default;

    //virtual void notify(std::string event) override;

private:
    scene_manager _scene_manager;
    load_manager _load_manager;
    draw_manager _draw_manager;
};

#endif
