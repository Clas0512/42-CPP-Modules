#include "PresidentialPardonForm.hpp"	

PresidentialPardonForm::PresidentialPardonForm() : AForm(0, 0, "Shrubbery"), _target("no target")
{
	std::cout << "Presidential Default Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(25, 5, "Presidential"), _target(target)
{
	std::cout << "Presidential Target Constructor Call" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : _target("copy" + copy.getTarget())
{
	*this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential Default Destructor Call" << std::endl;
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const &other)
{
	(void) other;
	return (*this);
}

std::string PresidentialPardonForm::getTarget() const
{
    return (_target);
}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	checkSignAndExec(executor);
	std::cout << BLUE << getTarget() << END << GREEN << " has been pardoned by Zaphod Beeblebrox." << END << std::endl;
}