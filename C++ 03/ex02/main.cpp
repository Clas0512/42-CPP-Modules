#include "FragTrap.hpp"

int main(void)
{
    ClapTrap a;
    ClapTrap b("Adem");
    ClapTrap c(b);

    std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;

    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());
    std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;
    std::cout << "Six hours later.." << std::endl;
    b.beRepaired(20);
    std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;
    std::cout << c.getName() << std::endl;

    std::cout << std::endl;

    FragTrap d;
    FragTrap dc(d);


    std::cout << "d name:" << d.getName() << std::endl;
    std::cout << "d hit:" << d.getHitPoints() << std::endl;
    std::cout << "d AttackDamage:" << d.getAttackDamage() << std::endl;
    std::cout << "d EnergyPoints:" << d.getEnergyPoints() << std::endl << std::endl;

    std::cout << "dc name:" << dc.getName() << std::endl;
    std::cout << "dc hit:" << dc.getHitPoints() << std::endl;
    std::cout << "dc AttackDamage:" << dc.getAttackDamage() << std::endl;
    std::cout << "dc EnergyPoints:" << dc.getEnergyPoints() << std::endl;
    
    d.attack(dc.getName());
    dc.takeDamage(d.getAttackDamage());

    std::cout << "d name:" << d.getName() << std::endl;
    std::cout << "d hit:" << d.getHitPoints() << std::endl;
    std::cout << "d AttackDamage:" << d.getAttackDamage() << std::endl;
    std::cout << "d EnergyPoints:" << d.getEnergyPoints() << std::endl << std::endl;

    std::cout << "dc name:" << dc.getName() << std::endl;
    std::cout << "dc hit:" << dc.getHitPoints() << std::endl;
    std::cout << "dc AttackDamage:" << dc.getAttackDamage() << std::endl;
    std::cout << "dc EnergyPoints:" << dc.getEnergyPoints() << std::endl;

    return (0);
}