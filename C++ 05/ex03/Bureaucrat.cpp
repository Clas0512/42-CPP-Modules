#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Anonymous"), _grade(150)
{
    std::cout << "Default Constructor Call" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        std::cout << "Bureaucrat is constructed with name and grade" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name + " Copy")
{
    std::cout << "Copy Constructor Call" << std::endl;
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    this->_grade = other._grade;
    return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Destructor Call" << std::endl;
}

std::string Bureaucrat::getName(void) const
{
    return (_name);
}

int Bureaucrat::getGrade(void) const
{
    return (_grade);
}

void    Bureaucrat::incrementGrade()
{
    if (_grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    _grade--;

}

void    Bureaucrat::decrementGrade()
{
    if (_grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    _grade++;
}

void    Bureaucrat::signForm(AForm &signForm) const
{
    try
    {
        std::cout << _name << " signs " << signForm.getName() << std::endl;
        signForm.beSigned(*this);
    }
    catch(const std::exception& e)
    {
        std::cout << WHITE << e.what() << END << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form) const
{
    try
    {
		std::cout << _name << " executes " << form.getName() << std::endl;
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
		std::cout << WHITE << e.what() << END << std::endl;
    }
}

std::ostream& operator<<(std::ostream &o, const Bureaucrat &other)
{
    o << other.getName() << ", bureaucrat grade " << other.getGrade();
    return (o);
}
