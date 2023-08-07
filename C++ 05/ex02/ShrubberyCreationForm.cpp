#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : _target("no target")
{
	std::cout << "Shrubbery Default Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(145, 137, "Shrubbery"), _target(target)
{
	std::cout << "Shrubbery Target Constructor Call" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy)
{
	*this = copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery Default Destructor Call" << std::endl;
}

ShrubberyCreationForm &	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other)
{
	this->zort = other.getTarget();
}

std::string ShrubberyCreationForm::getTarget() const
{
    return (_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	
}