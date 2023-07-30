#include "Animal.hpp"

Animal::Animal(){}

Animal::~Animal(){}

Animal::Animal(const Animal &copy)
{
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    this->type = copy.type;
    return (*this);
}

std::string	Animal::getType() const
{
    return (type);
}
