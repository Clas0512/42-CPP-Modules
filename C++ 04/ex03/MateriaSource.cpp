#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for(int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
	std::cout << "Materia Source is constructed." << std::endl;
}

MateriaSource::MateriaSource( MateriaSource const & copy)
{
	*this = copy;
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < 4; i++)
		if (this->inventory[i])
			delete this->inventory[i];
	std::cout << "Materia Source is destroyed." << std::endl;
}

MateriaSource&	MateriaSource::operator=( MateriaSource const & otherMateriaSource)
{
	for(int i = 0; i < 4; i++){
		if (this->inventory[i]){
			delete this->inventory[i];
		}
		this->inventory[i] = otherMateriaSource.inventory[i]->clone();
	}
	return *this;
}

AMateria*	MateriaSource::createMateria( std::string const & type )
{
	for ( int i = 0; i < 4; i++ )
        if (this->inventory[i] && this->inventory[i]->getType() == type)
            return this->inventory[i]->clone();
    return 0;
}

void	MateriaSource::learnMateria( AMateria* m)
{
	for (int i = 0; i < 4; i++)
	{
        if (!this->inventory[i]){
            this->inventory[i] = m;
			std::cout << "Materia " << m->getType() << " has been learned by MateriaSource" << std::endl;
            break;
        }
		else if(i == 4){
			for(int j = 0; j < 2147483647; j++){
				if (!this->droppedToTheFloor[j]){
					this->droppedToTheFloor[j] = m;
				}
			}
			std::cout << "MateriaSource's slots are full and the Materia left to the ground" << std::endl;
		}
	}
}