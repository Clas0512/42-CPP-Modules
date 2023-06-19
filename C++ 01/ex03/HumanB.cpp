#include "HumanB.hpp"

void    HumanB::attack(){
    std::cout << name + ": attacks with their " + weapon[0].getType() << std::endl;
}

void    HumanB::setWeapon(Weapon newWeapon){
    this->weapon = &newWeapon;
}

HumanB::HumanB(std::string name){
    this->name = name;
    weapon = NULL;
}