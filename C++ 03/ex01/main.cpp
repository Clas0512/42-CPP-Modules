#include "ScavTrap.hpp"

int main(void)
{
	ClapTrap *clapTrapHorde = new ClapTrap[3];
	ClapTrap target("Zort");
	for (int i = 0; i < 3; i++)
	{
		clapTrapHorde[i].attack(target.getName());
		target.takeDamage(clapTrapHorde[i].getAttackDamage());
	}
	target.beRepaired(3);
	delete [] clapTrapHorde;

	ScavTrap ssccaavv;

	ssccaavv.attack("Zort");
	ssccaavv.beRepaired(10);
	ssccaavv.guardGate();
	ssccaavv.takeDamage(12);
	ssccaavv.takeDamage(1);
	return (0);
}