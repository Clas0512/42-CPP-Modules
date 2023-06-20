#include "Zombie.hpp"

Zombie::Zombie(std::string name){
    Name = name;
}

Zombie::Zombie(void){
    ;
}

void    Zombie::setName(std::string name){
    Name = name;
}

void    Zombie::announce(){
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << "--" + Name + "-- is died..." << std::endl;
}