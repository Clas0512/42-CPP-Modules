#include "Weapon.hpp"

std::string    Weapon::getType(){
    return (this->type);
}

void    Weapon::setType(std::string newType){
    this->type = newType;
}

Weapon::Weapon(const std::string weapon){
    type = weapon;
}