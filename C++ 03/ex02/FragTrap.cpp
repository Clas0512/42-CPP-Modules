#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	static int i;
	std::stringstream ss;
	std::string temp;
	ss << i;
	ss >> temp;
	name = std::string("FragTrap " + temp);
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "<FragTrap> " << name << " is created." << std::endl;
	i++;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	hitPoints = 100;
	maxHP = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "<FragTrap> " +  name << " is created." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "<FragTrap> " << name << " deleted." << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "<FragTrap> " << name << ": High Five!" << std::endl;
}   