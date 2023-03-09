#ifndef CODE_OFFICESUPPLIES_H
#define CODE_OFFICESUPPLIES_H

#include <iostream>
#include <string>

class OfficeSupplies
{
    std::string type;
    std::string manufacturer;
    long int quantity;

public:
    OfficeSupplies(const char *, const char *, long int);
    std::string const & getManufacturer();
    long int getQuantity();
};


#endif //CODE_OFFICESUPPLIES_H
