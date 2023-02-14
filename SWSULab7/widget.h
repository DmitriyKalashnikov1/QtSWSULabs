#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr); //объявление конструктора
    ~Widget();//объявление деструктора

private:
    Ui::Widget *ui;// главный указатель на граф. интерфейс
protected:
    void paintEvent(QPaintEvent*) override; // переопределяемый метод для рисования
};
#endif // WIDGET_H
