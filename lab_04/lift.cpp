#include "lift.h"
#include <QPalette>

lift::lift(QObject *parent) : QObject(parent)
{
    this->_controller.setStyleSheet("background-color:green;");

    QObject::connect(&_cabin, SIGNAL(floor_finished(ssize_t, direction, bool)), &_controller, SLOT(passed_floor(ssize_t, direction, bool)));
    QObject::connect(&_cabin, SIGNAL(floor_passed(ssize_t, direction, bool)), &_controller, SLOT(passed_floor(ssize_t, direction, bool)));
    QObject::connect(&_controller, SIGNAL(new_target_signal(ssize_t)), &_cabin, SLOT(cabin_take_target(ssize_t)));
}

QWidget *lift::widget()
{
    return &this->_controller;
}
