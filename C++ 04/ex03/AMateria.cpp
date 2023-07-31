#include "AMateria.hpp"

AMateria::AMateria() : type(" "){}

std::string const &AMateria::getType() const
{
    return (type);
}

AMateria::AMateria(std::string const &type){
	this->type = type;
}

AMateria::AMateria(AMateria const &copy){
	*this = copy;
}

AMateria &AMateria::operator=(const AMateria &otherAMateria){
	this->type = otherAMateria.type;
	return *this;
}

AMateria::~AMateria(){
	return ;
}

void AMateria::use(ICharacter& target){
	std::cout << "AMateria " << this->type << " used on " << target.getName() << std::endl;
}
