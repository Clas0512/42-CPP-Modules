#include "HumanB.hpp"

void    HumanB::attack(){
    std::cout << name + ": attacks with their " + weapon.getType() << std::endl;
}

void    HumanB::setWeapon(Weapon newWeapon){
    this->weapon = newWeapon;
}

Weapon  *HumanB::getWeapon(){
    return &weapon;
}

HumanB::HumanB(std::string name){
    this->name = name;
}