#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "Ice.hpp"
# include "Cure.hpp"

class Character : public ICharacter
{
	private:
		std::string _name;
		AMateria *inventory[4];
		void *droppedToTheFloor[2147483647];
	public:
		~Character();
		Character(std::string const &name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		std::string const &getName() const;
		void equip(AMateria* mtr);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif