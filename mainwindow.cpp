#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QtDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_1,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_2,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_3,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_4,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_5,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_6,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_7,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_8,SIGNAL(released()),this,SLOT(press_digit()));
    connect(ui->pushButton_9,SIGNAL(released()),this,SLOT(press_digit()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::press_digit(){

    //qDebug() << "test";
    QPushButton * button = (QPushButton*)sender();
    ui->label->setText(button->text());
}
