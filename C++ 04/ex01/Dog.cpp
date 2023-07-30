#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor Call" << std::endl;
    type = "Dog";
    thisIsMyBrain = new Brain();

}

Dog::~Dog()
{
    std::cout << "Dog Default Destructor Call" << std::endl;
    delete thisIsMyBrain;
}

Dog::Dog(const Dog &copy)
{
    std::cout << "Dog Copy Constructor Call" << std::endl;
    *this = copy;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog Assignment Operator Overload Call" << std::endl;
    this->type = copy.type;
    return (*this);
}

void    Dog::makeSound() const
{
    std::cout << "Hav hav" << std::endl;
}
