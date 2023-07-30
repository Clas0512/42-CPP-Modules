#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor Call" << std::endl;
    type = "Cat";
    thisIsMyBrain = new Brain();
}

Cat::~Cat()
{
    std::cout << "Cat Default Destructor Call" << std::endl;
    delete thisIsMyBrain;
}

Cat::Cat(const Cat &copy)
{
    std::cout << "Cat Copy Constructor Call" << std::endl;
    *this = copy;
}

Cat &Cat::operator=(const Cat &copy)
{
    std::cout << "Cat Assignment Operator Overload Call" << std::endl;
    this->type = copy.type;
    return (*this);
}

void    Cat::makeSound() const
{
    std::cout << "Meow" << std::endl;
}
