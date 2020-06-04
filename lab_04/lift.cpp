#include "lift.h"
#include <QPalette>

lift::lift(QObject *parent) : QObject(parent)
{
    this->_controller.setStyleSheet("background-color:green;");

    QObject::connect(&_cabin, SIGNAL(floor_passed(ssize_t, direction)), &_controller, SLOT(passed_floor(ssize_t, direction)));
    QObject::connect(&_controller, SIGNAL(new_target_signal(ssize_t)), &_cabin, SLOT(cabin_take_target(ssize_t)));
    QObject::connect(&_controller, SIGNAL(stopped_signal(bool, ssize_t)), &_cabin, SLOT(cabin_stopped(bool, ssize_t)));
}

QWidget *lift::widget()
{
    return &this->_controller;
}
