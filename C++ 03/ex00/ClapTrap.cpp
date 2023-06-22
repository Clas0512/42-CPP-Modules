#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
    static int a;
    std::stringstream b;
    std::string d;
    b << a;
    b >> d;
    this->name = d;
    this->hitPoints = 10;
    this->attackDamage = 0;
    this->energyPoints = 10;
    std::cout << "ClapTrap Constructor Start the <" << name << ">" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hitPoints = 10;
    this->attackDamage = 0;
    this->energyPoints = 10;
    std::cout << "ClapTrap Constructor Start the <" << name << ">" << std::endl;
}

void	ClapTrap::attack(const std::string &target)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        std::cout << "ClapTrap <" << this->name << "> attacks <" << target << ">, causing <" << this->attackDamage << "> points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (this->hitPoints <= 0)
        std::cout << "ClapTrap <" << this->name << "> cannot attack because it's already dead." << std::endl;
    else if (this->energyPoints <= 0)
        std::cout << "ClapTrap <" << this->name << "> cannot attack because it doesn't have energy point enough!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap <" << name << "> takes <" << amount << "> points of damage!" << std::endl;
    if (amount - hitPoints >= 0)
        this->hitPoints -= amount;
    else
    {
        this->hitPoints = 0;
        std::cout << "ClapTrap died!" << std::endl;
    }
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hitPoints > 0 && this->energyPoints > 0)
    {
        if (this->hitPoints + amount > 10)
            this->hitPoints = 10;
        else
            this->hitPoints += amount;
    }
    else if (this->hitPoints <= 0)
        std::cout << "ClapTrap <" << this->name << "> cannot repair because it's already dead." << std::endl;
    else if (this->energyPoints <= 0)
        std::cout << "ClapTrap <" << this->name << "> cannot repair because it doesn't have energy point enough!" << std::endl;
}

std::string ClapTrap::getName()
{
    return this->name;
}

int ClapTrap::getAttackDamage()
{
    return this->attackDamage;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor destroy the <" << name << ">" << std::endl;
}