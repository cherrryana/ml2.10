#ifndef POINT_H
#define POINT_H

class QPainter;
class QPoint;
class Point
{
public:
    Point();
    Point(int x, int y, int size = 3, int thic = 1);

    int getX() const;
    void setX(int value);

    int getY() const;
    void setY(int value);

    int getSize() const;
    void setSize(int value);

    int getThic() const;
    void setThic(int value);

    void draw(QPainter *painter);
    int distance2(const QPoint &point);

private:
    int x, y, size, thic;
};

#endif // POINT_H
