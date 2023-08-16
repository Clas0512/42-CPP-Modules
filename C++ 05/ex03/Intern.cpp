#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void)
{
	std::cout << "Intern Default Constructor" << std::endl;
}

Intern::Intern(Intern const &copy)
{
	std::cout << "Intern Copy Constructor" << std::endl;
    *this = copy;
}

Intern &Intern::operator=(Intern const &other)
{
    (void) other;
	std::cout << "No Process" << std::endl;
    return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern Default Destructor" << std::endl;
}

static AForm *shrubberyCreation(std::string const target)
{
    return new ShrubberyCreationForm(target);
}

static AForm *robotomyRequest(std::string const target)
{
    return new RobotomyRequestForm(target);   
}

static AForm *presidentialPardon(std::string const target)
{
    return new PresidentialPardonForm(target);
}

const char *Intern::UnknownFormException::what() const throw()
{
    return "Undefined Form Name";
}

AForm *Intern::makeForm(std::string const formName, std::string const target) const
{
    AForm *r = NULL;
    std::string funcs[3] = {"shrubberyCreation", "robotomyRequest", "presidentialPardon"};
    funcArray formStringArray[3] = {&shrubberyCreation, &robotomyRequest, &presidentialPardon};
    int i = -1;
    while (i < 3)
    {
        i++;
        if (formName == funcs[i])
        {
            r = formStringArray[i](target);
            std::cout << "Intern creates " << r->getName() << std::endl;
            return r;
        }
    }
    throw UnknownFormException();
    return r;
}
