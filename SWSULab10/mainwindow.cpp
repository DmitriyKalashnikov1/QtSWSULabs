#include "mainwindow.h"
#include <qcustomplot.h>
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

float MainWindow::fun(double x){
    return pow(x,2.0)*exp(-x);
}

void MainWindow::on_Plot_clicked()
{
    int startX = ui->StartX->text().toInt();
    int stopX = ui->StopX->text().toInt();
    float stepX = ui->StepX->text().toFloat();

    QVector<double> x((stopX-startX)), y((stopX-startX)); // создаем два контейнера типа double с stopX-startX-тней элементов

    x[0]=startX;
    y[0] = fun(x[0]);
    ui->Table->insertRow(0);
    ui->Table->setItem(0,0, new QTableWidgetItem(QString::number(0)));
    ui->Table->setItem(0,1, new QTableWidgetItem(QString::number(x[0])));
    ui->Table->setItem(0,2, new QTableWidgetItem(QString::number(y[0])));
    for (int i=1; i<x.length(); i++)  // пробегаем по всем значениям x и считаем соответствущее y
    {
      x[i] = x[i-1] + stepX; //
     y[i] = fun(x[i]); // let's plot our function
     ui->Table->insertRow(i);
     ui->Table->setItem(i,0, new QTableWidgetItem(QString::number(i)));
     ui->Table->setItem(i,1, new QTableWidgetItem(QString::number(x[i])));
     ui->Table->setItem(i,2, new QTableWidgetItem(QString::number(y[i])));

    }
    // создаем график и привязываем к нему данные:
    ui->plotter->addGraph();
   ui->plotter->graph(0)->setData(x, y);
    // даем осям имена:
    ui->plotter->xAxis->setLabel("x");
    ui->plotter->yAxis->setLabel("y");
    // устанавливаем промежуток отображения на графике:
    ui->plotter->xAxis->setRange(startX, stopX);
    ui->plotter->yAxis->setRange(*std::min_element(y.begin(), y.end()), *std::max_element(y.begin(), y.end()));
    ui->plotter->replot();
}

