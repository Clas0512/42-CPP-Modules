#include "Zombie.hpp"

Zombie  *Zombie::zombieHorde(int N, std::string name){
    Zombie  **zombieArmy;
    for (size_t i = 0; i < N; i++)
        zombieArmy[i] = Zombie::newZombie(name);
    return zombieArmy[0];
}