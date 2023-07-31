#include "Ice.hpp"

Ice::Ice()
{
    std::cout << "Ice Default Constructor Call" << std::endl;
    type = "ice";
}

Ice::~Ice()
{
    std::cout << "Ice Desctructor Call" << std::endl;
}

AMateria *Ice::clone() const
{   
	return (new Ice(*this));
}

Ice::Ice(Ice const &copy)
{
    *this = copy;
}

Ice &	Ice::operator=(Ice const &other)
{
	this->type = other.type;
    return (*this);
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}