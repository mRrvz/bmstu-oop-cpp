#include "conversion_command.h"

conversion_command::conversion_command(cdata_t &_data)
{
    this->data = _data;
}

void move_command::execute(scene &scene)
{
    //scene.move(x, y, z);
}

void scale_command::execute(scene &scene)
{

}

void turn_command::execute(scene &scene)
{

}
