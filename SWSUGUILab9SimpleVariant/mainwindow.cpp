#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QImage>
#include <QFileDialog>

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


void MainWindow::on_read_clicked()
{
   QString file = QFileDialog::getOpenFileName(this); // берем название файла, выбраное через проводник виндовс
    input.load(file); // загружаем изображение
    output.load(file);
    ui->input->setPixmap(QPixmap::fromImage(input)); // выводим изображенияе на экран
    isRead = true; // флаг считывания в true
}


void MainWindow::on_convert_clicked()
{
    if (isRead){ // если изображение считано успешно
        for (int y = 0; y < input.height(); ++y) { // пробегаемся по 'строчкам' картинки
            QRgb *inpLine = reinterpret_cast<QRgb*>(input.scanLine(y)); // считываем строчки перемеенные
            QRgb *outLine = reinterpret_cast<QRgb*>(output.scanLine(y));
            for (int x = 0; x < input.width(); ++x) { // пробегаемся по пискселям строчки
                QRgb &inpPix = inpLine[x]; // считычиваем значения цветов пикселя, определяем его яркость как среднее арифметическое и если яркость больше порога -- красим в белый
                QRgb &outPix = outLine[x];
                int red = qRed(inpPix);
                int green = qGreen(inpPix);
                int blue = qBlue(inpPix);
                float averange = (red*0.56+green*0.33+blue*0.11);
                if (averange > threshold){
                    outPix = qRgba(255, 255, 255, qAlpha(inpPix));
                }else{
                outPix = qRgba(qRed(inpPix), qGreen(inpPix),qBlue(inpPix), qAlpha(inpPix));
                }
            }
        }
         ui->output->setPixmap(QPixmap::fromImage(output)); // выводим результат преобразования
    }else{
        ui->statusbar->showMessage("Nothing to convert, click 'Read' before"); // если изображение не считано -- выводим предупреждение
    }

}


void MainWindow::on_threshold_valueChanged(int value)
{
    threshold = value; // сохраняем значение ползунка в отдельную переменную
    ui->statusbar->showMessage("Threshold:" + QString::number(threshold), 2000); //выводим полученное значение на экран
}

