#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPainter>
#include <QRect>
#include <QBrush>
#include <QFont>
#include <iostream>
#include <QMessageBox>
#include "character.h"

char ch='0';
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::update()
{
    this->repaint();
}

void  MainWindow ::keyPressEvent (QKeyEvent *e)
{
        if(e->modifiers () == Qt::ControlModifier)
        {
            if(e->key () == Qt::Key_W)
            {

                qDebug()<<tr("快捷键W");

            }
            if(e->key () == Qt::Key_S)
            {
                qDebug()<<tr("快捷键S");
            }
            if(e->key () == Qt::Key_A)
            {
                qDebug()<<tr("快捷键A");
            }
            if(e->key () == Qt::Key_D)
            {
                qDebug()<<tr("快捷键D");
            }
        }
        else
        {
            if(e->key())
            {

               Q.save(e->key());
               qDebug()<<e->key();
               this->update();
                 //MainWindow::paintEvent(true);
            }


        }

}

/*
void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);


QPainter paint(this);
paint.begin(this);
Q.Display(paint);
paint.end();
}
*/


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    // 设置画笔颜色
    painter.setPen(QColor(100, 160, 230));

    // 设置字体：微软雅黑、点大小50、斜体
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setPointSize(80);
    painter.setFont(font);

    // 绘制文本

    QRectF rect(10,20,100,1000);

    painter.drawText(rect, Q.display());          // 创建QPainter一个对象

  /*  // 画一条直线
    QPen pen;
    pen.setColor(Qt::yellow);           // 设置画笔为黄色
    painter.setPen(pen);                // 设置画笔
    painter.drawLine(rect().topLeft(), rect().bottomRight());

    // 画一个空心矩形
    pen.setColor(Qt::darkRed);
    painter.setPen(pen);
    painter.drawRect(QRect(1, 1, 100, 100));


*/
}

