#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    double first_N;
    double second_N;
    int checked = 0;
    bool need_to_clear = false;

private slots:
    void press_digit();
    void negative();
    void decimal();
    void clear();
    void plus();
    void equal();
    void minus();
    void X();
    void devide();
};
#endif // MAINWINDOW_H
