#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_name = "Anonymous FragTrap";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap Default Constructor is running." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
    std::cout << "FragTrap Name Constructor is running." << std::endl;
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor is running." << std::endl;	
}

FragTrap::FragTrap(const FragTrap &copy)
{
	std::cout << "FragTrap Copy constructor is running." << std::endl;
	*this = copy;
}

FragTrap &FragTrap::operator=(const FragTrap &arg)
{
	this->_name = arg._name;
	this->hitPoints = arg.hitPoints;
	this->attackDamage = arg.attackDamage;
	this->energyPoints = arg.energyPoints;
	std::cout << "FragTrap Assignment Operator Overload is running." << std::endl;
	return (*this);
}

void FragTrap::attack(const std::string &target)
{
	if (energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " has no energy points for attack!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "FragTrap " << _name << " takes " << amount << " points of damage." << std::endl;
	hitPoints -= amount;
	if (hitPoints <= 0)
		std::cout << "FragTrap " << _name << " is died.." << std::endl;
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << "FragTrap " << _name << " has no energy points for repair!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << _name << " be repaired for " << amount << " points" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

std::string FragTrap::getName(void)
{
	return (_name);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << ": High Fives Guys !!" << std::endl;
}

