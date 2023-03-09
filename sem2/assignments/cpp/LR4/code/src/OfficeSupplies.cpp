#include "../headers/OfficeSupplies.h"

OfficeSupplies::OfficeSupplies(const char *type, const char *manufacturer, long int quantity)
{
    this->type = type;
    this->manufacturer = manufacturer;
    this->quantity = quantity;
}

std::string const & OfficeSupplies::getManufacturer()
{
    return manufacturer;
}

long int OfficeSupplies::getQuantity()
{
    return quantity;
}