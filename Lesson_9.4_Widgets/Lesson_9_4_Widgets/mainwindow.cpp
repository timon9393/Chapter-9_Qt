#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Lesson_9.4_Widgets");

    ui->groupBox->setTitle("Выберите тип прогресс бара");
    ui->radioButton->setText("Горизонтальный");
    ui->radioButton_2->setText("Вертикальный");
    ui->radioButton->setChecked(true);

    ui->comboBox->addItem("Вариант 1");
    ui->comboBox->addItem("Вариант 2");
    ui->comboBox->addItem("Вариант 3");
    ui->comboBox->addItem("Вариант 4");
    ui->comboBox->addItem("Вариант 5");

    ui->pushButton->setCheckable(true);
    ui->pushButton->setText("Увеличить значение");

    ui->progressBar->setMinimum(0);
    ui->progressBar->setMaximum(10);
    ui->progressBar->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->progressBar->value() >= 10)
        ui->progressBar->setValue(0);
    else
        ui->progressBar->setValue(ui->progressBar->value() + 1);
}

void MainWindow::on_radioButton_clicked()
{
    ui->progressBar->setOrientation(Qt::Horizontal);
}

void MainWindow::on_radioButton_2_clicked()
{
        ui->progressBar->setOrientation(Qt::Vertical);
}

