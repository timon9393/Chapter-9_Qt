#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    sWatch = new stopwatch(this);
    isActive = false;
    connect(sWatch, &stopwatch::timeChanged, this, &MainWindow::update_time);
    ui->pb_startStop->setText("Старт");
    ui->pb_clear->setText("Очистить");
    ui->pb_lap->setText("Круг");
    ui->pb_lap->setEnabled(false);
    ui->l_time->setText(sWatch->get_time());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_startStop_clicked()
{
    isActive = !isActive;

    if(isActive)
    {
        sWatch->start();
        ui->pb_startStop->setText("Стоп");
        ui->pb_lap->setEnabled(true);
    } else {
        sWatch->stop();
        ui->pb_startStop->setText("Старт");
        ui->pb_lap->setEnabled(false);
    }
}

void MainWindow::update_time()
{
    ui->l_time->setText(sWatch->get_time());
}

void MainWindow::on_pb_lap_clicked()
{
    ui->tb_browser->append(sWatch->lap_time());
}

void MainWindow::on_pb_clear_clicked()
{
    if (isActive)
    {
        ui->tb_browser->clear();
        MainWindow::on_pb_startStop_clicked();
        sWatch->reset_all();
        ui->l_time->setText(sWatch->get_time());
    }
    else
    {
        ui->tb_browser->clear();
        sWatch->reset_all();
        ui->l_time->setText(sWatch->get_time());
    }
}

