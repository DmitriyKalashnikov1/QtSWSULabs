#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <QFileDialog>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this); // настраиваем внешний вид полей, отрываем файл на запись и чтение и пишем в него числа
    ui->first_num->setText("First num: ");
    ui->second_num->setText("Second num: ");
    ui->diff->setText("Diff: ");
    ui->sum->setText("Sum: ");

}

MainWindow::~MainWindow()
{
    infile.close(); // закрываем файл в деструкторе
    delete ui;
}


void MainWindow::on_read_b_clicked() // по клику на кнопку 'Read' считываем числа из файла, считаем сумму, разность, выводим в UI
{
int i;
float f;
float sum;
float diff;
QString file = QFileDialog::getOpenFileName(this); // открываем файловый диалог и получаем иммя файла на чтение
infile.open(file.toStdString(), ios::in);
if (!infile.is_open()){
    ui->first_num->setText("Error opening file");
}


infile.seekp(0, ios::beg);

infile >> i >> f;
infile.close();
ui->first_num->setText("First num: "+QString::number(i));
ui->second_num->setText("Second num: "+QString::number(f));
sum = f + i;
ui->sum->setText("Sum: "+QString::number(sum));
diff = i - f;
ui->diff->setText("Diff: "+QString::number(diff));
}


void MainWindow::on_write_b_clicked()
{
    QString file = QFileDialog::getOpenFileName(this); // открываем файловый диалог и получаем иммя файла на запись
    infile.open(file.toStdString(), ios::out);
    if (!infile.is_open()){
        ui->first_num->setText("Error opening file");
    }
    infile << 10 << ' ' << 2.5 << endl ;

    infile.close();
}

