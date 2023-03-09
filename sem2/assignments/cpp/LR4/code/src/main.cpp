#include <iostream>
#include <vector>

#include "../headers/Point.h"
#include "../headers/OfficeSupplies.h"

void firstTask(Point *);
void secondTask(Point *);
void thirdTask();

int main()
{
    const int number_of_objects = 4;
    Point *points = new Point[number_of_objects];

    points[0].setX(0);
    points[0].setY(0);

    points[1].setX(10);
    points[1].setY(0);

    points[2].setX(10);
    points[2].setY(5);

    points[3].setX(0);
    points[3].setY(5);

    bool userQuit = false;
    char userMenuChoice;
    while (!userQuit)
    {
        std::cout << "Задание 1" << std::endl;
        std::cout << "Задание 2" << std::endl;
        std::cout << "Задание 3" << std::endl;
    }

    delete[]points;
}

void firstTask(Point * points)
{
    std::cout << "Длины сторон: " << Point::getDistance(points[0], points[1]) << "; "
              << Point::getDistance(points[1], points[2]) << std::endl;
    std::cout << "Длина диагонали: " << Point::getDistance(points[0], points[2]) << std::endl;
}

void secondTask(Point *point)
{
    std::cout << "Площадь: " << getSquare(point[0], point[2]) << std::endl;
}

void thirdTask()
{
    std::vector<OfficeSupplies> supplies;
    supplies.emplace_back("type0", "man0", 10);
    supplies.emplace_back("type1", "man1", 20);
    supplies.emplace_back("type2", "man2", 30);
    supplies.emplace_back("type3", "man3", 40);
    supplies.emplace_back("type4", "man4", 50);
    supplies.emplace_back("type5", "man5", 60);

    std::string userManufacturer;
    std::cout << "Производитель: ";
    std::cin >> userManufacturer;

    long int supply_quantity = 0;
    for (auto &supply_unit: supplies)
        if (supply_unit.getManufacturer() == userManufacturer)
            supply_quantity += supply_unit.getQuantity();

    std::cout << "Количество товаров: " << supply_quantity << std::endl;
}

double getSquare(Point &a, Point &b)
{
    return fabs((b.x - a.x) * (b.y - a.y));
}
