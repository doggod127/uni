#ifndef CODE_TASK_3_H
#define CODE_TASK_3_H

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <limits>

#define FILE_RECORD_WIDTH 20

struct office_supplies
{
    int id;
    std::string type;
    std::string manufacturer;
    int quantity;
};

void debug_print(std::vector<struct office_supplies> &);

void thirdTask(std::string &, std::vector <struct office_supplies> &);

int countProductByFirm(std::string &, std::vector<struct office_supplies> &);
void writeToFile(std::string &, std::vector<struct office_supplies> &);
void readFromFile(std::string &, std::vector<struct office_supplies> &);
void readFromFileById(std::string &, std::string &, std::vector<struct office_supplies> &);

#endif //CODE_TASK_3_H
