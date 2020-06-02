#include "cabin.h"
#include <QDebug>

cabin::cabin(QObject *parent)
{
    this->status = FREE;
    this->current_floor = 1;
    this->need_floor = 1;
    this->_direction = STOP;

    QObject::connect(&_door, SIGNAL(closed_signal()), this, SLOT(cabin_moving()));
    QObject::connect(&move_timer, SIGNAL(timeout()), this, SLOT(cabin_moving()));

    QObject::connect(this, SIGNAL(moving_signal()), this, SLOT(cabin_moving()));
    QObject::connect(this, SIGNAL(stopped_signal()), this, SLOT(cabin_stopped()));
    QObject::connect(this, SIGNAL(stopped_signal()), &_door, SLOT(opening()));
}

void cabin::cabin_moving()
{
    if (status != FREE)
    {
        this->status = MOVING;

        if (current_floor == need_floor)
        {
            emit stopped_signal();
        }
        else
        {
            move_timer.start(MOVING_TIME);
            emit floor_passed(current_floor, this->_direction, false);
            this->_direction = current_floor > need_floor ? DOWN : UP;
            this->current_floor = current_floor > need_floor ? current_floor - 1 : current_floor+ + 1;
        }
    }
}

void cabin::cabin_stopped()
{
    this->status = FREE;
    this->move_timer.stop();
    emit floor_finished(this->current_floor, this->_direction, true);
}

void cabin::cabin_take_target(ssize_t floor)
{
    this->status = GET;
    this->need_floor = floor;

    if (this->current_floor == this->need_floor)
    {
        emit stopped_signal();
    }
    else
    {
        this->_direction = need_floor > current_floor ? UP : DOWN;
        emit moving_signal();
    }
}
