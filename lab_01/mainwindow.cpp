#include "mainwindow.h"
#include "ui_mainwindow.h"

static figure_t figure;

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
    delete ui;
}

double MainWindow::get_value(const QString string_value)
{
    return ui->dx_box->valueFromText(string_value);
}

void MainWindow::on_load_button_clicked(void)
{
    fname_t name = "data.csv";
    err_t error_code;

    free_figure(figure);

    if ((error_code = load_figure(name, figure)))
    {
        handle_error(error_code);
    }

    draw_figure(figure, ui->graphicsView->scene());
}

void MainWindow::on_move_button_clicked(void)
{
    move_t coeffs;

    coeffs.dx = get_value(ui->dx_box->text());
    coeffs.dy = get_value(ui->dy_box->text());
    coeffs.dz = get_value(ui->dz_box->text());

    move_figure(figure.points, coeffs);
    draw_figure(figure, ui->graphicsView->scene());
}

void MainWindow::on_scale_button_clicked(void)
{
    scale_t coeffs;

    coeffs.kx = get_value(ui->kx_box->text());
    coeffs.ky = get_value(ui->ky_box->text());
    coeffs.kz = get_value(ui->kz_box->text());

    scale_figure(figure.points, coeffs);
    draw_figure(figure, ui->graphicsView->scene());
}

void MainWindow::on_turn_button_clicked(void)
{
    turn_t coeffs;

    coeffs.ox = get_value(ui->ox_box->text());
    coeffs.oy = get_value(ui->oy_box->text());
    coeffs.oz = get_value(ui->oz_box->text());

    turn_figure(figure.points, coeffs);
    draw_figure(figure, ui->graphicsView->scene());
}
