#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QVBoxLayout>
#include <vector>
#include <QDebug>
#include <memory>

#include "button.h"

#define FLOOR_COUNT 9
#define DOORS_TIME  500
#define MOVING_TIME 3000

enum direction
{
    DOWN = -1,
    STOP = 0,
    UP = 1
};

class controller : public QWidget
{
    Q_OBJECT;

    enum controller_status
    {
        FREE,
        BUSY
    };

public:
    explicit controller(QWidget *parent = nullptr);
    ~controller() = default;

public slots:
    void new_target(ssize_t floor);
    void passed_floor(ssize_t floor, direction direction_, bool is_stopped);

signals:
    void new_target_signal(ssize_t floor);

private:
    controller_status status;
    direction _direction;
    int current_floor;

    std::vector<std::shared_ptr<button>> buttons;
    std::vector<bool> visited_floors;
    std::unique_ptr<QVBoxLayout> layout;

    bool target_exist(ssize_t &new_floor);
};

#endif
