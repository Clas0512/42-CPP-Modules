#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
    _name = "Anonymous ScavTrap";
    hitPoints = 100;
    energyPoints = 50;
    attackDamage = 20;
    std::cout << "ScavTrap Default Constructor is running." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
    std::cout << "ScavTrap Name Constructor is running." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
{
	std::cout << "ScavTrap Copy constructor is running." << std::endl;
	*this = copy;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &arg)
{
	std::cout << "ScavTrap Assignment Operator Overload is running." << std::endl;
	this->_name = arg._name;
	this->hitPoints = arg.hitPoints;
	this->attackDamage = arg.attackDamage;
	this->energyPoints = arg.energyPoints;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor is running." << std::endl;
}

void    ScavTrap::attack(const std::string &target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points for attack!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints--;
}

void ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage." << std::endl;
	hitPoints -= amount;
	if (hitPoints <= 0)
		std::cout << "ScavTrap " << _name << " is died.." << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " has no energy points for repair!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << _name << " be repaired for " << amount << " points" << std::endl;
	hitPoints += amount;
	energyPoints--;
}

std::string	ScavTrap::getName(void)
{
	return (_name);
}

void    ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is guard mode now." << std::endl;
}
