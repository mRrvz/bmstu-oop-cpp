#ifndef CABIN_H
#define CABIN_H

#include <QObject>

#include "door.h"

class cabin : public QObject
{
public:
    cabin();

private:
    door _door;
};

#endif // CABIN_H
