#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Constructor Call" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Copy Constructor Call" << std::endl;
	*this = copy;
}

Brain &	Brain::operator=(const Brain &copy)
{
	std::cout << "Brain Assignment Operator Overload Call" << std::endl;
	*this->ideas = *copy.ideas;
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Call" << std::endl;
}
