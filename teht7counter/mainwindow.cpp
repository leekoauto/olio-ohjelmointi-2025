#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), counter(0)
{
    ui->setupUi(this);

    ui->lineEdit->setText(QString::number(counter));

    connect(ui->countButton, &QPushButton::clicked, this, &MainWindow::incrementCounter);
    connect(ui->resetButton, &QPushButton::clicked, this, &MainWindow::resetCounter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::incrementCounter()
{
    counter++;
    ui->lineEdit->setText(QString::number(counter));
}

void MainWindow::resetCounter()
{
    counter = 0;
    ui->lineEdit->setText(QString::number(counter));
}
