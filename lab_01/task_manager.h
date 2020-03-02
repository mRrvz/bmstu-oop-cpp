#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "errors.h"
#include "figure.h"

enum data
{
    LOAD,
    SCALE,
    TURN,
    MOVE,
    DRAW,
    QUIT
};

struct request
{
    int task;
    union
    {
        fname_t file_name;
        scale_t scale;
        turn_t turn;
        move_t move;
        plane_t plane;
    };
};

using request_t = struct request;

err_t task_manager(const request_t &request);

#endif
