#include "ClapTrap.hpp"

int main(void){
    
    ClapTrap a;
    ClapTrap b("Adem");
    ClapTrap c(b);

    a.attack(b.getName());
    b.takeDamage(a.getAttackDamage());

    std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;

    std::cout << "Six hours later.." << std::endl;

    b.beRepaired(20);

    std::cout << b.getName() << " hitPoints : " << b.getHitPoints() << std::endl;

    std::cout << c.getName() << std::endl;
    return (0);
}