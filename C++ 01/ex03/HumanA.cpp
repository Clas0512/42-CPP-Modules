#include "HumanA.hpp"

void    HumanA::attack(){
    std::cout << name + ": attacks with their " + weapon.getType() << std::endl;
}

HumanA::HumanA(std::string name, std::string weaponType){
    this->name = name;
    this->weapon.setType(weaponType);
}