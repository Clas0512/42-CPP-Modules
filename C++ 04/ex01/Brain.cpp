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
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain Destructor Call" << std::endl;
}
