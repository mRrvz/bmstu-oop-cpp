#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "../drawer.h"
#include "../scene.h"

class draw_manager
{
public:
    draw_manager() = default;
    draw_manager(draw_manager &manager) : _drawer(manager._drawer), current_cam(manager.current_cam) {};
    ~draw_manager() = default;

    void draw_model(const model &model);
    void set_drawer(std::shared_ptr<base_drawer>);
    void set_cam(std::shared_ptr<camera>);

private:
    std::shared_ptr<base_drawer> _drawer;
    std::shared_ptr<camera> current_cam;
};

#endif