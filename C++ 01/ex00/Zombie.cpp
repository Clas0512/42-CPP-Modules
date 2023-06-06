#include "Zombie.hpp"

void    Zombie::announce(void){
    std::cout << Name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << "--" + Name + "-- is died..." << std::endl;
}