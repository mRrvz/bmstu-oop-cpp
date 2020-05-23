#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "../component/camera.h"
#include "../scene.h"

class scene_manager
{
public:
    scene_manager();
    ~scene_manager() = default;

    std::shared_ptr<scene> get_scene() const;
    std::shared_ptr<camera> get_cam() const;

    void set_scene(std::shared_ptr<scene> scene_);
    void next_cam();

private:
    std::shared_ptr<scene> _scene;
    std::shared_ptr<camera> current_cam;
};

#endif
