#include "AMateria.hpp"

AMateria::AMateria()
{}  

std::string const & AMateria::getType() const
{
    return (&type);
}


AMateria::AMateria(std::string const & type)
{
	
}

void	AMateria::use(ICharacter& target)
{
	
}