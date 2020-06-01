#include "button.h"

button::button(QWidget *parrent) : QPushButton(parrent)
{
    QObject::connect(this, SIGNAL(clocked()), this, SLOT(pressed()));
    QObject::connect(this, SIGNAL(), this, SLOT(finish()));

    this->status = not_active;
    this->button_floor = 1;
}

void button::set_floor(const ssize_t &floor)
{
    this->button_floor = floor;
}

void button::pressed()
{
    this->status = active;
    this->setDisabled(true);
    //this->
}

void button::finish()
{
    this->status = not_active;
    this->setDisabled(false);
}
