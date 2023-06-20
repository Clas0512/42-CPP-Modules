#include "Zombie.hpp"

int main()
{
    Zombie *zombi = newZombie("zombi 1");
    Zombie *zombiMom = new Zombie("Zombi Mom");
    randomChump("ADEM BERKE");
    zombi->announce();
    zombiMom->announce();
    delete zombi;
    delete zombiMom;
    return 0;
}