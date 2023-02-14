#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); //конструктор главного окна
    ~MainWindow(); // деструктор главного окна

private slots: // колбеки
    void on_read_clicked(); // нажатие на кнопку считать картинку

    void on_convert_clicked(); // нажатие на кнопку конвертации

    void on_threshold_valueChanged(int value); // смена положения ползунка

private:
    Ui::MainWindow *ui; // указатель на интерфейс
    bool isRead = false; // флаг указывающий а считано ли изображение
    int threshold = 0; // переменная, хранящая значение с ползунка
    QImage input; // входное изображение
    QImage output; // выходное изображение
};
#endif // MAINWINDOW_H
