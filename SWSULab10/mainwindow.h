#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <math.h>
#include <qcustomplot.h>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // констурктор
    ~MainWindow(); // деструктор
    float fun(double x); // матиматическая функция

private slots:
    void on_Plot_clicked();

private:
    Ui::MainWindow *ui; // указатель на интерфейс
};
#endif // MAINWINDOW_H
