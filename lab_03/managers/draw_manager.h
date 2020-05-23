#ifndef DRAW_MANAGER_H
#define DRAW_MANAGER_H

#include "../drawer.h"
#include "../scene.h"
#include "../component/camera.h"

class draw_manager
{
public:
    draw_manager() = default;
    ~draw_manager() = default;

    void draw(scene &scene_obj, base_drawer &drawer_obj, camera &camera_obj);
};

#endif
