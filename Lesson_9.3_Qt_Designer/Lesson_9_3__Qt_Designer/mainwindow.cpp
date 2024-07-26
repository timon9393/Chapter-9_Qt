#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    newWindow = new Dialog();
    newWindow->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete newWindow;
}

void MainWindow::on_pb_connectDB_clicked()
{
    newWindow->show();
}

