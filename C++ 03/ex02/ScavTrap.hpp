#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
        ScavTrap(const ScavTrap &copy);
        ScavTrap &operator=(const ScavTrap &arg);
		void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void);
		void guardGate();
};

#endif