#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class Point;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    Point *points[25];
    int k = 0, f = 0, ind =0;
    QPoint Start;
    void move(const QPoint &start);
};
#endif // MAINWINDOW_H
