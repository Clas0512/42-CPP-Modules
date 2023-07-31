#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		~Ice();
		AMateria *clone() const;
		Ice(Ice const &copy);
		Ice &operator=(Ice const &other);
		void use(ICharacter &target);
};

#endif