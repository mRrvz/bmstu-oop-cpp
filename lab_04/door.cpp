#include "door.h"
#include "controller.h"

door::door()
{
    this->status = CLOSED;

    QObject::connect(&opening_timer, SIGNAL(timeout()), this, SLOT(opened()));
    QObject::connect(&opened_timer,  SIGNAL(timeout()), this, SLOT(closing()));
    QObject::connect(&closing_timer, SIGNAL(timeout()), this, SLOT(closed()));
}

void door::opening()
{
    if (status == CLOSED || status == CLOSING)
    {
        qDebug() << "Двери открываются.";

        if (this->status == CLOSED)
        {
            this->status = OPENING;
            this->opening_timer.start(DOORS_TIME);
        }
        else
        {
            this->status = OPENING;
            auto timer = closing_timer.remainingTime();
            closing_timer.stop();
            this->opening_timer.start(DOORS_TIME - timer);
        }
    }
}

void door::opened()
{
    if (status == OPENING)
    {
        this->status = OPEN;
        qDebug() << "Двери открыты!";
        this->opened_timer.start(DOORS_TIME);
    }
}

void door::closing()
{
    if (status == OPEN)
    {
        this->status = CLOSING;
        qDebug() << "Двери закрываются.";
        this->closing_timer.start(DOORS_TIME);
    }
}

void door::closed()
{
    if (status == CLOSING)
    {
        this->status = CLOSED;
        qDebug() << "Двери закрыты.";
        emit closed_signal();
    }
}
