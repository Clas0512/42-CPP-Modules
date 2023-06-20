#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
    {
        Weapon club = Weapon("crude spiked club");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("zort club");
        bob.attack();
    }
    {
        // Weapon club = Weapon("spiked club");
        HumanB jim("Jim");
        // jim.setWeapon(club);
        jim.attack();
        Weapon clubb = Weapon("spiked club");
        clubb.setType("zort club");
        jim.setWeapon(clubb);
        jim.attack();
    }
return 0;
}