#include "ClapTrap.hpp"

ClapTrap::ClapTrap(name)
{
	Name = name;
}

ClapTrap::~ClapTrap()
{
	
}

void	ClapTrap::attack(const std::string &target)
{
	target.takeDamage(this->attackDamage);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	
}