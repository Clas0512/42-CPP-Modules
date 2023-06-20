#include "HumanB.hpp"

void    HumanB::attack(){
    if (weapon == NULL)
        std::cout << name + ": attacks with their HAND" << std::endl;
    else
        std::cout << name + ": attacks with their " + weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &newWeapon){
    weapon = &newWeapon;
}

HumanB::HumanB(std::string name){
    this->name = name;
    this->weapon = NULL;
}
