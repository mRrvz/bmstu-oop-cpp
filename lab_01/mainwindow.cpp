#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QGraphicsScene *scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);
    scene->setSceneRect(0, 0, WIN_X, WIN_Y);
}

MainWindow::~MainWindow(void)
{
    request_t request;
    request.task = QUIT;
    request_handler(request);

    delete ui;
}

err_t MainWindow::draw_actions(void)
{
    plane_t plane;
    plane.scene = ui->graphicsView->scene();
    plane.width = plane.scene->width();
    plane.height = plane.scene->height();

    request_t request;
    request.task = DRAW;
    request.plane = plane;

    err_t error_code = request_handler(request);

    return error_code;
}

void MainWindow::on_load_button_clicked(void)
{
    fname_t name = "data.csv";
    request_t request;

    request.task = LOAD;
    request.file_name = name;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        handle_error(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        handle_error(error_code);
    }
}

void MainWindow::on_move_button_clicked(void)
{
    move_t coeffs;
    coeffs.dx = ui->dx_box->value();
    coeffs.dy = ui->dy_box->value();
    coeffs.dz = ui->dz_box->value();

    request_t request;
    request.task = MOVE;
    request.move = coeffs;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        handle_error(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        handle_error(error_code);
    }
}

void MainWindow::on_scale_button_clicked(void)
{
    scale_t coeffs;
    coeffs.kx = ui->kx_box->value();
    coeffs.ky = ui->ky_box->value();
    coeffs.kz = ui->kz_box->value();

    request_t request;
    request.task = SCALE;
    request.scale = coeffs;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        handle_error(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        handle_error(error_code);
    }
}

void MainWindow::on_turn_button_clicked(void)
{
    turn_t coeffs;
    coeffs.ox = ui->ox_box->value();
    coeffs.oy = ui->oy_box->value();
    coeffs.oz = ui->oz_box->value();

    request_t request;
    request.task = TURN;
    request.turn = coeffs;

    err_t error_code = request_handler(request);
    if (error_code)
    {
        handle_error(error_code);
        return;
    }

    error_code = draw_actions();
    if (error_code)
    {
        handle_error(error_code);
    }
}
