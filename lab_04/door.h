#ifndef DOOR_H
#define DOOR_H

#include <QObject>

class door : public QObject
{
    Q_OBJECT;

private:
    enum door_status
    {
        OPEN,
        OPENING,
        CLOSING,
        CLOSE
    };

public:
    door();
    ~door() = default;

    door_status status;


signals:
    void door_closed();
    void door_opened();
};

#endif
