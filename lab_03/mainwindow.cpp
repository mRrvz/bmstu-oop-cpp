#include "mainwindow.h"
//#include "ui_mainwindow.h"

//#include "vector/vector.hpp"
//#include "vector/iterator.hpp"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    _facade(nullptr)
{
    ui->setupUi(this);
    this->setup_scene();
    this->_facade = std::shared_ptr<facade>(facade::instance());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_move_button_clicked()
{
    move_model move_command(10, 10, 10, 1);
    move_command.execute(_facade);
    update_scene();
}

void MainWindow::on_scale_button_clicked()
{
    scale_model scale_command(2, 2, 2, 1);
    scale_command.execute(_facade);
    update_scene();
}

void MainWindow::on_turn_button_clicked()
{
    turn_model turn_command(3, 3, 3, 1);
    turn_command.execute(_facade);
    update_scene();
}

void MainWindow::on_load_button_clicked()
{
    load_model load_command("/home/alexey/reps/oop/lab_03/data/model.csv");
    load_command.execute(_facade);
    update_scene();
}

void MainWindow::setup_scene()
{
    this->_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->_scene->setSceneRect(0, 0, win_x, win_y);
}

void MainWindow::update_scene()
{
    std::shared_ptr<qt_drawer> drawer(new qt_drawer(this->_scene));
    draw_scene draw_command(drawer);
    draw_command.execute(_facade);
}

void MainWindow::on_add_camera_clicked()
{
    add_camera camera_command(win_x / 2, win_y / 2, 0);
    camera_command.execute(_facade);
}
