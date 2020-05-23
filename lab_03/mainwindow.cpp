#include "mainwindow.h"
//#include "ui_mainwindow.h"

//#include "vector/vector.hpp"
//#include "vector/iterator.hpp"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _facade(nullptr),
    ui(new Ui::MainWindow)
{
    //facade _facade();
    //this->facade = _facade;

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
    move_model command(10, 10, 10, 0);
    command.execute(_facade);

    //draw_scene draw_obj;
    //draw_obj.execute();

}

void MainWindow::on_scale_button_clicked()
{
    scale_model command(3, 3, 3, 0);
    command.execute(_facade);

}

void MainWindow::on_turn_button_clicked()
{
    turn_model command(3, 3, 3, 0);
    command.execute(_facade);
}

void MainWindow::on_load_button_clicked()
{
    load_model command("/home/alexey/reps/oop/lab_03/data/model.csv");
    command.execute(_facade);

}

void MainWindow::setup_scene()
{
    this->_scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(_scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    this->_scene->setSceneRect(0, 0, win_x, win_y);
}

void MainWindow::init_facade()
{
    /*
    scene _scene();
    load_manager load();
    draw_manager draw();
    */

}
