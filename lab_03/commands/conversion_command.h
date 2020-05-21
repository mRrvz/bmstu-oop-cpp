#ifndef CONVETSION_COMMAND_H
#define CONVETSION_COMMAND_H

#include "command.h"
#include "../scene.h"

struct conversion_data
{
    double x;
    double y;
    double z;
};

using cdata_t = struct conversion_data;

class conversion_command : public base_command
{
public:
    conversion_command(cdata_t &data);

protected:
    cdata_t data;
};

class move_command : public conversion_command
{
public:
    move_command(cdata_t &data) : conversion_command(data) {};

    void execute(scene &scene);
};

class scale_command : public conversion_command
{
public:
    scale_command(cdata_t &data) : conversion_command(data) {};

    void execute(scene &scene);
};

class turn_command : public conversion_command
{
public:
    turn_command(cdata_t &data) : conversion_command(data) {};

    void execute(scene &scene);
};



#endif
