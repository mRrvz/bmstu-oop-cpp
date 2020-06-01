#ifndef LIFT_H
#define LIFT_H

#include <QObject>

#include "controller.h"
#include "cabin.h"

class lift : public QObject
{
    Q_OBJECT;
public:
    explicit lift(QObject *parent = nullptr);
    ~lift() = default;

    QWidget *widget();

private:
    controller _controller;
    cabin _cabin;
};

#endif
