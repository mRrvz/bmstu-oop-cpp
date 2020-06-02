#ifndef CABIN_H
#define CABIN_H

#include <QObject>
#include "door.h"
#include "controller.h"

class cabin : public QObject
{
    Q_OBJECT;

    enum cabin_status
    {
        GET,
        FREE,
        MOVING
    };

public:
    explicit cabin(QObject *parent = nullptr);
    ~cabin() = default;

public slots:
    void cabin_moving();
    void cabin_take_target(ssize_t floor);
    void cabin_stopped();

signals:
    void floor_finished(ssize_t floor, direction dir, bool);
    void floor_passed(ssize_t floor, direction dir, bool);

private:
    door _door;
    ssize_t current_floor;
    ssize_t need_floor;

    direction _direction;
    cabin_status status;

    QTimer move_timer;

signals:
    void moving_signal();
    void stopped_signal();
};

#endif
