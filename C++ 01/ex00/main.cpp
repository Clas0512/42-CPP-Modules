#include "Zombie.hpp"

int main()
{
    Zombie zombi = Zombie("zombi 1");
    Zombie *zombiMom = newZombie("Zombi Mom");
    zombiMom[0].announce();
    randomChump("ADEM BERKE");
    return 0;
}