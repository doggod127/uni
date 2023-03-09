#include "../headers/task_3.h"

void debug_print(std::vector<struct office_supplies> &supplies)
{
    std::cout << std::left;
    for (auto &supply: supplies)
        std::cout << std::setw(5) << supply.id << std::setw(20) << supply.type << std::setw(20) << supply.manufacturer
                  << std::setw(20) << supply.quantity << std::endl;
}

void thirdTask(std::string &file_name, std::vector<struct office_supplies> &supplies)
{
    std::string desiredFirm;
    std::cout << "Фирма для поиска: ";
    std::cin >> desiredFirm;

    writeToFile(file_name, supplies);
    std::cout << "Количество товаров фирмы: " << countProductByFirm(desiredFirm, supplies) << std::endl;
}

void writeToFile(std::string &file_name, std::vector<struct office_supplies> &supplies)
{
    std::fstream output_file;
    output_file.open("../" + file_name);
    if (!output_file.is_open())
    {
        std::cout << "Failed to open file " << file_name << std::endl;
        std::cout << "Reason: file not found" << std::endl;
        return;
    }

    output_file << std::left;

    for (auto & supply_unit: supplies)
        output_file << std::setw(FILE_RECORD_WIDTH) << supply_unit.id;
    output_file << std::endl;

    for (auto & supply_unit: supplies)
        output_file << std::setw(FILE_RECORD_WIDTH) << supply_unit.type;
    output_file << std::endl;

    for (auto & supply_unit: supplies)
        output_file << std::setw(FILE_RECORD_WIDTH) <<supply_unit.manufacturer;
    output_file << std::endl;

    for (auto & supply_unit: supplies)
        output_file << std::setw(FILE_RECORD_WIDTH) << supply_unit.quantity;
    output_file<< std::endl;

    output_file.close();
}

void readFromFile(std::string &file_name, std::vector<struct office_supplies> &supplies)
{
    std::fstream output_file;
    output_file.open("../" + file_name);
    if (!output_file.is_open())
    {
        std::cout << "Failed to open file " << file_name << std::endl;
        std::cout << "Reason: file not found" << std::endl;
        return;
    }

    while (!output_file.eof())
    {
        for (auto &supply: supplies)
            output_file >> supply.id;

        for (auto &supply: supplies)
            output_file >> supply.type;

        for (auto &supply: supplies)
            output_file >> supply.manufacturer;

        for (auto &supply: supplies)
            output_file >> supply.quantity;
    }

    output_file.close();
}

void readFromFileById(std::string &file_name, std::string &id, std::vector<struct office_supplies> &supplies)
{
    std::fstream output_file;
    output_file.open("../" + file_name);
    if (!output_file.is_open())
    {
        std::cout << "Failed to open file " << file_name << std::endl;
        std::cout << "Reason: file not found" << std::endl;
        return;
    }

    std::string buffer;
    size_t record_array_index;

    for (record_array_index = 0; record_array_index < supplies.size(); record_array_index++)
    {
        output_file >> buffer;
        if (buffer == id)
            break;
    }

    output_file.seekg(0);

    output_file.ignore(FILE_RECORD_WIDTH * record_array_index);
    output_file >> supplies[record_array_index].id;
    output_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    output_file.ignore(FILE_RECORD_WIDTH * record_array_index);
    output_file >> supplies[record_array_index].type;
    output_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    output_file.ignore(FILE_RECORD_WIDTH * record_array_index);
    output_file >> supplies[record_array_index].manufacturer;
    output_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    output_file.ignore(FILE_RECORD_WIDTH * record_array_index);
    output_file >> supplies[record_array_index].quantity;
    output_file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    output_file.close();
}


int countProductByFirm(std::string &manufacturer_name, std::vector<struct office_supplies> &supplies)
{
    int quantity = 0;

    for (auto &supply_unit: supplies)
        if (supply_unit.manufacturer == manufacturer_name)
            quantity += supply_unit.quantity;

    return quantity;
}

