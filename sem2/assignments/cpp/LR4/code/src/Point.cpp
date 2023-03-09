#include "../headers/Point.h"

double Point::getDistance(Point &a, Point &b)
{
    return sqrt(
            (b.getX() - a.getX()) * (b.getX() - a.getX()) +
            (b.getY() - a.getY()) * (b.getY() - a.getY())
    );
}

Point::Point()
{
    std::cout << "Constructor for Point" << std::endl;
    x = 0;
    y = 0;
}

Point::~Point()
{
    std::cout << "Destructor for Point" << std::endl;
}

double Point::getX()
{
    return x;
}

double Point::getY()
{
    return y;
}

void Point::setX(double x)
{
    this->x = x;
}

void Point::setY(double y)
{
    this->y = y;
}