#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : _target("no target")
{
	std::cout << "Robotomy Default Constructor Call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(72, 45, "Robotomy"), _target(target)
{
	std::cout << "Robotomy Target Constructor Call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy)
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Default Destructor Call" << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	this->zort = other.getTarget();
}

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int roboto;
	std::cout << "Lak lak LAk lok lakkk!" << std::endl;
	roboto = rand() % 2;
	if (roboto)
		std::cout << PURPLE << _target << END << " was robotomized" << std::endl;
	else
		std::cout << PURPLE << _target << END << " was not robotomized" << std::endl;
}