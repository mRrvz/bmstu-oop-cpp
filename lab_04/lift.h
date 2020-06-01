#ifndef LIFT_H
#define LIFT_H

#include <QObject>

class lift : QObject
{
    Q_OBJECT;
public:
    explicit lift(QObject *parent = nullptr);
};

#endif
