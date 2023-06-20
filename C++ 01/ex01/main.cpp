#include "Zombie.hpp"

int main(){
    Zombie *Suru1 = zombieHorde(5, "Monkeys");
    for (size_t i = 0; i < 5; i++)
        Suru1[i].announce();
    
    // std::cout << zombi.getName() << std::endl;
    // zombi[0].zombieHorde(10, "suru1");
    // std::cout << zombi[0].getName() << std::endl;
    return 0;
}