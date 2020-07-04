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
    connect(ui->pushButton_decimal,SIGNAL(released()),this,SLOT(decimal()));
    connect(ui->pushButton_negative,SIGNAL(released()),this,SLOT(negative()));
    connect(ui->pushButton_clear,SIGNAL(released()),this,SLOT(clear()));
    connect(ui->pushButton_plus,SIGNAL(released()),this,SLOT(plus()));
    connect(ui->pushButton_equal,SIGNAL(released()),this,SLOT(equal()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::press_digit(){

    if (need_to_clear){
         ui->label->clear();
         need_to_clear = false;
    }
    QPushButton * button = (QPushButton*)sender();
    QString new_number;

    new_number = ui->label->text() + button->text();

    ui->label->setText(new_number);
}

void MainWindow::decimal(){

    QString new_number = ui->label->text() + ".";
    ui->label->setText(new_number);

}

void MainWindow::negative(){

    QString new_number = "-" + ui->label->text();
    ui->label->setText(new_number);
}


void MainWindow::clear(){

    ui->label->setText("");

}

void MainWindow::plus(){

    if (checked > 0){
        equal();
    }

    checked = 1;
    first_N = (ui->label->text()).toDouble();
    need_to_clear = true;

}

void MainWindow::equal(){

    second_N = (ui->label->text()).toDouble();

    if(checked == 1){
        QString new_number = QString::number(first_N + second_N, 'g', 15);
        ui->label->setText(new_number);
    }

    checked = 0;


}












