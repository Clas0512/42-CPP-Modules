#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name){
    Zombie *zombieArmy = new Zombie();
    for (int i = 0; i < N; i++)
        zombieArmy[i].setName(name);
    return zombieArmy;
}