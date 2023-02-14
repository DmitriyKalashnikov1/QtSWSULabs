#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <fstream> // файловый ввод-вывод
#include <QFileDialog>
using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr); // конструктор
    ~MainWindow(); // деструктор

private slots: // функции-колбеки
    void on_read_b_clicked(); // колбек на клик по кнопке "Read"

    void on_write_b_clicked();

private:
    Ui::MainWindow *ui; // Указатель на интерфейс
    fstream infile; // файл с данными
};
#endif // MAINWINDOW_H
