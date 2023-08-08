#include "PresidentialPardonForm.hpp"	

PresidentialPardonForm::PresidentialPardonForm() : _target("no target")
{
	std::cout << "Presidential Default Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(25, 5, "Presidential"), _target(target)
{
	std::cout << "Presidential Target Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy)
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Default Destructor Call" << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	this->zort = other.getTarget();
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
    return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
}