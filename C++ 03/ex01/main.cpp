#include "ScavTrap.hpp"

int main(void)
{
    // ClapTrap a;
    // ClapTrap b("Adem");
    // ClapTrap c(b);

    // std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;

    // a.attack(b.getName());
    // b.takeDamage(a.getAttackDamage());
    // std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;
    // std::cout << "Six hours later.." << std::endl;
    // b.beRepaired(20);
    // std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;
    // std::cout << c.getName() << std::endl;

    // std::cout << std::endl;

    ScavTrap d;

    std::cout << "d name: " << d.getName() << std::endl;
    std::cout << d.getHitPoints() << std::endl;

    std::cout << std::endl;

    ScavTrap e(d);
    std::cout << "e name: " << e.getName() << std::endl;

    std::cout << std::endl;

    e.takeDamage(1);

    return (0);
}