#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm(0, 0, "Shrubbery"), _target("no target")
{
	std::cout << "Robotomy Default Constructor Call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(72, 45, "Robotomy"), _target(target)
{
	std::cout << "Robotomy Target Constructor Call" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : _target("copy" + copy.getTarget())
{
	*this = copy;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy Default Destructor Call" << std::endl;
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const &other)
{
	(void) other;
	return (*this);
}

std::string RobotomyRequestForm::getTarget() const
{
    return (_target);
}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int roboto;
	checkSignAndExec(executor);
	std::cout << CLAY << "Lak lak LAk lok lakkk!" << END << std::endl;
	srand(time(0));
	roboto = rand() % 2;
	std::cout << roboto << std::endl;
	if (roboto)
		std::cout << BLUE << _target << END << GREEN << " was robotomized" << END << std::endl;
	else
		std::cout << BLUE << _target << END << RED << " was not robotomized" << END << std::endl;
}