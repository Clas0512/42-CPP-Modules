#include "Dog.hpp"

Dog::Dog()
{
    type = "Dog";
    std::cout << "Dog Default Constructor Call" << std::endl;
    thisMyBrain = new Brain();

}

Dog::~Dog()
{
    std::cout << "Dog Default Destructor Call" << std::endl;
    delete thisMyBrain;
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

}

void    Dog::newBrain()
{
    std::cout << "Dog newBrain Method Call" << std::endl;
}

void    Dog::makeSound() const
{
    std::cout << "Hav hav" << std::endl;
}
