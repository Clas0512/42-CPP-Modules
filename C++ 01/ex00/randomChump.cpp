#include "Zombie.hpp"

void    randomChump(std::string name){
    Zombie *chump = newZombie(name);
    chump->announce();
}