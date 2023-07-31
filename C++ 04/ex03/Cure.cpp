#include "Cure.hpp"

Cure::Cure()
{
	std::cout << "Cure Default Constructor Call" << std::endl;
	type = "cure";
}

Cure::~Cure()
{
	std::cout << "Cure Desctructor Call" << std::endl;
}

AMateria *Cure::clone() const
{
	return (new Cure(*this));
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

void	Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds  *" << std::endl;
}