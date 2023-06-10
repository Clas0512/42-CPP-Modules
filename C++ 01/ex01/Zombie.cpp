#include "Zombie.hpp"

void    Zombie::announce(){
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string name){
    Name = name;
}

Zombie::~Zombie(){
    std::cout << "--" + Name + "-- is died..." << std::endl;
}