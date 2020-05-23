#ifndef FACADE_H
#define FACADE_H

#include "scene.h"
#include "../managers/load_manager.h"
#include "../managers/draw_manager.h"
#include "../managers/scene_manager.h"

class facade
{
public:
    static std::shared_ptr<facade> instance()
    {
        static std::shared_ptr<facade> _facade(new facade());

        return _facade;
    }

    ~facade() = default;

    void load_model(std::string fname);
    void remove_model(const size_t &index);

    void add_camera();
    void remove_camera(const size_t &index);

private:
    facade() = default;
    facade(const facade &) = delete;
    facade &operator=(const facade &) = delete;

    scene_manager _scene_manager;
    load_manager _load_manager;
    draw_manager _draw_manager;
};

#endif
