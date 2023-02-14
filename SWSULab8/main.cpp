#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //создаем приложение
    MainWindow w; // наше главное окно
    w.show(); // запускаем главный цикл программы
    return a.exec();
}
