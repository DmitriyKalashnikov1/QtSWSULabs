#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // создаем объект приложения
    MainWindow w; // создаем главное окно
    w.show(); // отображаем
    return a.exec();
}
