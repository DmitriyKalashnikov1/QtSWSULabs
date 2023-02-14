#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // создаем приложение
    Widget w; // наш виджет
    w.show(); // отображаем
    return a.exec();
}
