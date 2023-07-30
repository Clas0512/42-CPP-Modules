#include "Ice.hpp"

Ice::Ice()
{
    type = "ice";
}

Ice::~Ice()
{}

Ice::Ice(Ice const &copy)
{
    *this = copy;
}

Ice &	Ice::operator=(Ice const &other)
{
	this->type = other.type;
    return (*this);
}

AMateria *Ice::clone() const
{   
	return (new Ice());
}

void	Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}