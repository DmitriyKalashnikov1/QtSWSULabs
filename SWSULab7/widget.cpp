#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter canvas; //create a 'canvas'
    QBrush Brush; //create a Brush
    QFont Font("Times New Roman", 80); //create Font
    QPen pen; //create pen printing text
    //устанавливаем нужные настройки для шрифта
    Font.setBold(true);
    Font.setItalic(true);
    // настройка кисти для фона
    Brush.setColor(Qt::blue);
    Brush.setStyle(Qt::SolidPattern);
    canvas.begin(this);
    canvas.setFont(Font);// установка шрифта и кисти в canvas
    canvas.setBrush(Brush);
    canvas.drawRect(0,0, width(), height()); // закрашиваем фон
    Brush.setColor(Qt::green); // рисуем концетрические окружности
    canvas.setBrush(Brush);
    int x = 240;
    int y = 150;
    canvas.drawEllipse(x, y, 300, 300);
    Brush.setColor(Qt::yellow);
    canvas.setBrush(Brush);
    canvas.drawEllipse(x+50, y+50, 200, 200);
    Brush.setColor(Qt::white);
    canvas.setBrush(Brush);
    canvas.drawEllipse(x+100, y+100, 100, 100);

    pen.setColor(Qt::darkBlue); // выводим текст
    canvas.setPen(pen);

    canvas.drawText(QPoint(x, y+60), "Калашников");
    canvas.end();
}

