#ifndef REQUEST_H
#define REQUEST_H

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

err_t request_handler(const request_t &request);

#endif
