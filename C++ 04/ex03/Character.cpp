#include "Character.hpp"

Character::~Character()
{
	std::cout << "Character Default Destructor Call" << std::endl;
    for(int i = 0; i < 4; i++){
		if(this->inventory[i])
			delete this->inventory[i];
	}
	std::cout << this->_name << " has died." << std::endl;
}

Character::Character(std::string const &name) : _name(name)
{}

Character::Character(Character const &copy)
{
    std::cout << "Character Copy Constructor Call" << std::endl;
    *this = copy;
}

Character &Character::operator=(Character const &other)
{
	this->_name = other._name;
	for(int i = 0; i < 4; i++){
		if (this->inventory[i]){
			delete this->inventory[i];
		}
		this->inventory[i] = other.inventory[i]->clone();
	}
    std::cout << "Character " << this->_name << " is cloned." << std::endl;
	return (*this);
}

std::string const &Character::getName() const
{
    return (_name);
}

void	Character::equip(AMateria* mtr)
{
	for (int i = 0; i < 4; i++){
		if (!this->inventory[i]){
			this->inventory[i] = mtr;
			std::cout << "Materia " << mtr->getType() << " is equipped by " << this->_name << std::endl;
			break;
		}
		else if (i == 4){
			for (int j = 0; j < 2147483647; j++){
				if (!this->droppedToTheFloor[j]){
					this->droppedToTheFloor[j] = mtr;
				}
			}
			std::cout << "Character's inventory are full. The Materia is dropped to the ground" << std::endl;
		}
	}
}

void	Character::unequip(int idx)
{
    if (!this->inventory[idx]){
        std::cout << "No materia in there !" << std::endl;
        return ;
    }
    else {
        for (int i = 0; i < 2147483647; i++)
            if (!this->droppedToTheFloor[i])
                this->droppedToTheFloor[i] = this->inventory[idx];
        this->inventory[idx] = 0;
        std::cout << getName() << " unequipped " << this->inventory[idx]->getType() << " materia" << std::endl;
    }
}

void	Character::use(int idx, ICharacter& target)
{
    if (this->inventory[idx]){
        std::cout << this->getName() << " " << std::endl;
        this->inventory[idx]->use(target);
    }
}