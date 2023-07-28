#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Anonymous")
{
	std::cout << "Default constructor is running." << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name) : _name(name)
{
	std::cout << "Name constructor is running." << std::endl;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "Copy constructor is running." << std::endl;
	*this = copy;
}

ClapTrap & ClapTrap::operator=(const ClapTrap &arg)
{
	std::cout << "Assignment Operator Overload is running." << std::endl;
	this->_name = arg._name;
	this->hitPoints = arg.hitPoints;
	this->attackDamage = arg.attackDamage;
	this->energyPoints = arg.energyPoints;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor is running." << std::endl;
}

void    ClapTrap::attack(const std::string &target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points for attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void    ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage." << std::endl;
	hitPoints -= amount;
	if (hitPoints <= 0)
		std::cout << "ClapTrap " << _name << " is died.." << std::endl;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " has no energy points for repair!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << _name << " be repaired for " << amount << " points" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

std::string ClapTrap::getName()
{
	return (_name);
}

unsigned int ClapTrap::getAttackDamage()
{
	return (attackDamage);
}

unsigned int ClapTrap::getHitPoints()
{
	return (hitPoints);
}

unsigned	int ClapTrap::getEnergyPoints()
{
	return (energyPoints);
}
