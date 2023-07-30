#include "WrongCat.hpp"

WrongCat::WrongCat()
{
    type = "WrongCat";
    std::cout << "WrongCat Default Constructor Call" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Default Destructor Call" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy)
{
    std::cout << "WrongCat Copy Constructor Call" << std::endl;
    *this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &copy)
{
    std::cout << "WrongCat Assignment Operator Overload Call" << std::endl;
    this->type = copy.type;
    return (*this);
}

void    WrongCat::makeSound() const
{
    std::cout << "WrongMeow" << std::endl;
}
