#ifndef BRAIN_HPP
# define BRAIN_HPP

# include "Animal.hpp"

class Brain
{
	private:
        std::string ideas[100];
	public:
		Brain();
		Brain(const Brain &copy);
		Brain &operator=(Brain const &copy);
		~Brain();
            
};

#endif