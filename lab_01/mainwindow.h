#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "figure.h"
#include "errors.h"

#define WIN_X 989
#define WIN_Y 569

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_load_button_clicked();

    void on_move_button_clicked();

    void on_scale_button_clicked();

    void on_turn_button_clicked();

private:
    Ui::MainWindow *ui;
};

#endif 
