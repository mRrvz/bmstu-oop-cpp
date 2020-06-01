#ifndef DOOR_H
#define DOOR_H

#include <QObject>
#include <QDebug>
#include <QTimer>

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

public slots:
    void opened();
    void closed();

private slots:
    void opening();
    void closing();

signals:
    void closed_signal();
    void open_signal();

private:
    door_status status;

    QTimer opening_timer;
    QTimer closing_timer;
    QTimer opened_timer;
};

#endif
