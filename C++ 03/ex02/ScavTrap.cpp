#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	static int i;
	std::stringstream ss;
	std::string temp;
	ss << i;
	ss >> temp;
	name = std::string("ScavTrap " + temp);
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "<ScavTrap> " << name << " is created." << std::endl;
	i++;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "<ScavTrap> " +  name << " is created." << std::endl;
} 

ScavTrap::~ScavTrap()
{
	std::cout << "<ScavTrap> " << name << " deleted." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "<ScavTrap> " << name << " is guard mode now." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0)
	{
		std::cout << "<ScavTrap> " + this->name + " attacks " +  target + ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "<ScavTrap> " + this->name + "'s energy is too low to attack." << std::endl;
}