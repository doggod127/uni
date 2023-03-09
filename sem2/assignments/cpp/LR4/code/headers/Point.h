#ifndef CODE_POINT_H
#define CODE_POINT_H

#include <iostream>
#include <cmath>

class Point
{
    double x, y;

public:
    Point();
    ~Point();

    double getX();
    double getY();

    void setX(double);
    void setY(double);

    static double getDistance(Point &, Point &);

    friend double getSquare(Point &, Point &);
};


#endif //CODE_POINT_H
