#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie{
    private:
        std::string Name;
    public:
        std::string getName(){
            return this->Name;
        }
        void    announce();
        Zombie(std::string name);
        ~Zombie();
};
    Zombie  *newZombie(std::string name);
    void    randomChump(std::string name);

#endif
