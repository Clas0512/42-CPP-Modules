#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor Call" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal Default Destructor Call" << std::endl;
}

Animal::Animal(const Animal &copy)
{
    std::cout << "Animal Copy Constructor Call" << std::endl;
    *this = copy;
}

Animal &Animal::operator=(const Animal &copy)
{
    std::cout << "Animal Assignment Operator Overload Call" << std::endl;
    this->type = copy.type;
    return (*this);
}

std::string	Animal::getType() const
{
    return (type);
}

void    Animal::makeSound() const
{
    std::cout << "Undefined sound" << std::endl;
}
