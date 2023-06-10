#include "Weapon.hpp"

std::string    Weapon::getType(){
    std::string &Type = this->type;
    return (Type);
}

void    Weapon::setType(std::string newType){
    this->type = newType;
}

Weapon::Weapon(const std::string weapon){
    type = weapon;
}