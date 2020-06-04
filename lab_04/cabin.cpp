#include "cabin.h"
#include <QDebug>

cabin::cabin(QObject *parent)
{
    this->status = FREE;
    this->current_floor = 1;
    this->need_floor = 1;
    this->_direction = STOP;

    QObject::connect(&move_timer, SIGNAL(timeout()), this, SLOT(cabin_moving()));

    QObject::connect(this, SIGNAL(moving_signal()), this, SLOT(cabin_moving()));
    QObject::connect(this, SIGNAL(stopped_signal(bool, ssize_t)), this, SLOT(cabin_stopped(bool, ssize_t)));
    QObject::connect(this, SIGNAL(open_doors_signal()), &_door, SLOT(opening()));
}

void cabin::cabin_moving()
{
    if (status == MOVING || status == GET)
    {
        this->status = MOVING;
        move_timer.start(MOVING_TIME);

        qDebug() << "Лифт едет. Этаж: " << this->current_floor;
        emit floor_passed(current_floor, this->_direction);

        if (current_floor != need_floor)
        {
            this->_direction = current_floor > need_floor ? DOWN : UP;
            this->current_floor = current_floor > need_floor ? current_floor - 1 : current_floor + 1;
        }
    }
}

void cabin::cabin_stopped(bool is_last, ssize_t new_floor)
{
    if (is_last)
    {
        this->status = FREE;
    } else
    {
        this->status = GET;
        this->need_floor = new_floor;
    }

    this->move_timer.stop();
    emit open_doors_signal();
}

void cabin::cabin_take_target(ssize_t floor)
{
    this->status = GET;
    this->need_floor = floor;

    if (this->current_floor == this->need_floor)
    {
        emit floor_passed(current_floor, this->_direction);
    }
    else
    {
        this->_direction = need_floor > current_floor ? UP : DOWN;
        emit moving_signal();
    }
}

