#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include "vector/vector.hpp"
//#include "vector/iterator.hpp"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_move_button_clicked()
{
    /*
    int arr[5] = {1, 2,3,4,5};
    vector<int> vector(arr, 5);
    //qDebug() << vector.get_size();
    auto iterator = vector.begin();

    for (auto node: vector)
    {
        qDebug() << node;
    }
    */
}

void MainWindow::on_scale_button_clicked()
{

}

void MainWindow::on_turn_button_clicked()
{

}

void MainWindow::on_load_button_clicked()
{

}
