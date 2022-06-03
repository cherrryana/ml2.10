#include "point.h"
#include <QPainter>
#include <QPoint>

Point::Point(int x, int y, int size, int thic)
     : x(x), y(y), size(size), thic(thic)
{
}

int Point::getX() const
{
    return x;
}

void Point::setX(int newX)
{
    x = newX;
}

int Point::getY() const
{
    return y;
}

void Point::setY(int newY)
{
    y = newY;
}

int Point::getSize() const
{
    return size;
}

void Point::setSize(int newSize)
{
    size = newSize;
}

int Point::getThic() const
{
    return thic;
}

void Point::setThic(int newThic)
{
    thic = newThic;
}

void Point::draw(QPainter *painter)
{
    int t = getThic();
    QPen pen(Qt::black);
    pen.setWidth(t);
    painter -> drawLine(x, y + size, x, y - size);
    painter -> drawLine(x + size, y, x - size, y);


}

int Point::distance2(const QPoint &point)
{
    return (this -> x)^2 + (point.x())^2 + (this -> y)^2 + (point.y())^2;
}
