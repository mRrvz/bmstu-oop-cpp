#include "controller.h"

controller::controller(QWidget *parent) : QWidget(parent)
{
    this->layout = std::unique_ptr<QVBoxLayout>(new QVBoxLayout);
    this->setLayout(this->layout.get());

    for (int i = 0; i < FLOOR_COUNT; i++)
    {
        std::shared_ptr<button> btn(new button);
        btn->set_floor(FLOOR_COUNT - i);
        btn->setText(QString::number(FLOOR_COUNT - i));

        buttons.insert(buttons.begin(), btn);
        layout->addWidget(dynamic_cast<QPushButton *>(btn.get()));

        visited_floors.push_back(true);
        QObject::connect(btn.get(), SIGNAL(floor_pressed(ssize_t)), this, SLOT(new_target(ssize_t)));
    }
}

void controller::passed_floor(ssize_t floor, direction direction_)
{
    this->current_floor = floor;
    this->_direction = direction_;
    qDebug() << "Лифт едет. Проехал этаж: " << current_floor;
}

void controller::new_target(ssize_t floor)
{
    this->status = BUSY;
    this->visited_floors[floor - 1] = false;

    target_exist(floor);
    emit new_target_signal(floor);
}

void controller::finish_target(ssize_t floor, direction direction_)
{
    if (status == BUSY)
    {
        qDebug() << "Лифт остановился на этаже: " << floor;

        this->current_floor = floor;
        this->visited_floors[floor - 1] = true;
        this->_direction = direction_;

        emit this->buttons.at(floor - 1)->unpress_signal();

        if (target_exist(floor))
        {
            emit new_target_signal(floor);
        }
        else
        {
            this->status = FREE;
        }
    }
}

bool controller::target_exist(ssize_t &new_floor)
{
    int direction = _direction != STOP ? _direction : DOWN;

    for (int i = current_floor - 1; i >= 0 && i < FLOOR_COUNT; i += direction)
    {
        if (!visited_floors[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    for (int i = current_floor - 1; i >= 0 && i < FLOOR_COUNT; i += -direction)
    {
        if (!visited_floors[i])
        {
            new_floor = i + 1;
            return true;
        }
    }

    return false;
}
