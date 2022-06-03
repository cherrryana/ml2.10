#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "point.h"
#include <QPainter>
#include <QMouseEvent>
#include <QPoint>

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

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    for (int i = 0; i < k; i++)
        points[i] -> draw(&painter);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (f)
    {
        move(event -> pos());
        repaint();
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    if (f)
    {
        move(event -> pos());
        f = 0;
    }
}

void MainWindow::move(const QPoint &start)
{
    points[ind] -> setX(start.x());
    points[ind] -> setY(start.y());
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    Point *point = nullptr;
    if (k > 24) return;

    QPoint qpoint;
    qpoint.setX(event -> x());
    qpoint.setY(event -> y());

    int go = 0;

    for (int i = 0; i < k; i++)
    {
        if ((points[i] -> distance2(qpoint) < 4) & Qt::LeftButton)
        {
            Start = event -> pos();
            f = 1;
            go = 1;
            ind = i;
        }
    }

    if (go == 0)
    {
       point = new Point(event -> x(), event -> y());
       if (point)
         points[k] = point;
       k++;
    }
    repaint();
}

