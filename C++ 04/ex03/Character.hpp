#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>

class Character
{
	public:
		Character(void);
		Character(** replace parameters **);
		Character(Character const &instance);
		Character &operator=(Character const &rhs);
		~Character(void);

	private:

};

#endif