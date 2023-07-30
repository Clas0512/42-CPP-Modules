#include "Cure.hpp"

Cure::Cure()
{
	type = "cure";
}

Cure::~Cure()
{
	
}

Cure::Cure(Cure const &copy)
{
	*this = copy;
}

Cure &Cure::operator=(Cure const &other)
{
	this->type = other.type;
	return (*this);
}

AMateria *	Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds  *" << std::endl;
}