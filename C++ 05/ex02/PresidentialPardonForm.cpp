#include "PresidentialPardonForm.hpp"
# define PURPLE "\x1B[35m"
# define END "\033[0m"

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
	int roboto;
	std::cout << "Lak lak LAk lok lakkk!" << std::endl;
	roboto = rand() % 2;
	if (roboto)
		std::cout << PURPLE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << PURPLE << _target << END << " was not robotomized" << std::endl;
}