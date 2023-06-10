#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name){
    Zombie *zombieArmy;
    for (size_t i = 0; i < N; i++)
        zombieArmy = newZombie(name);
    return zombieArmy;
}