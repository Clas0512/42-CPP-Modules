#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	static int i;
	std::stringstream ss;
	std::string temp;
	ss << i;
	ss >> temp;
	name = std::string("ClapTrap " + temp);
	hitPoints = 10;
	maxHP = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "<ClapTrap> " << name << " is created." << std::endl;
	i++;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitPoints = 10;
	maxHP = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "<ClapTrap> <Name Constructor>" << name << " is created." << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "<ClapTrap> <destructor> " << name << " deleted." << std::endl; 
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	*this = copy;
	std::cout << "<Copy Constructor>" << copy.name << "is cloned." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap)
{
	std::cout << "Operator Overload terminated" << std::endl;
	this->name = clapTrap.name;
	this->hitPoints = clapTrap.hitPoints;
	this->energyPoints = clapTrap.energyPoints;
	return (*this);
}

void ClapTrap::attack(const std::string &target)
{
	if (this->energyPoints > 0)
	{
		std::cout << "<ClapTrap> " + this->name + " attacks " +  target + ", causing " << this->attackDamage << " points of damage!" << std::endl;
		energyPoints--;
	}
	else
		std::cout << "<ClapTrap> " + this->name + "'s energy is too low to attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints > 0)
	{
		std::cout << "<ClapTrap> " + this->name + " takes " << amount << " points of damage";
		this->hitPoints -= amount;
		if (this->hitPoints <= 0)
			std::cout << " and died";
		std::cout << "!" << std::endl;
	}
	else
		std::cout << "<ClapTrap> " + this->name + " is" + " already dead." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->energyPoints > 0)
	{
		if (this->hitPoints < maxHP)
		{
			std::cout << "<ClapTrap> " + this->name + " is repaired by " << amount << " points" << std::endl;
			this->hitPoints += amount;
			this->energyPoints--;
		}
		else
			std::cout << "<ClapTrap> " + this->name + " is already full health." << std::endl;
	}
	else
		std::cout << "<ClapTrap> " + this->name + "'s energy is too low to repair." << std::endl;
}

std::string ClapTrap::getName(void)
{
	return (this->name);
}

int ClapTrap::getAttackDamage(void)
{
	return (this->attackDamage);
}