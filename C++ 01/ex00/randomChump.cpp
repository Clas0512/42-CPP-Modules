#include "Zombie.hpp"

void    Zombie::randomChump(std::string name){
    Zombie *chump = Zombie::newZombie(name);
    chump->announce();
}