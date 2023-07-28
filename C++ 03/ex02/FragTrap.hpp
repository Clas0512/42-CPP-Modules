#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
        FragTrap(const FragTrap &copy);
        FragTrap &operator=(const FragTrap &arg);
		void attack(const std::string &target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        std::string getName(void);
		void highFivesGuys(void);
};

#endif