#include "AForm.hpp"

AForm::AForm() : _name("Unknown"), _gradeToSign(150), _gradeToExec(150)
{
    _signed = false;
	std::cout << "Default AForm Constructor Call" << std::endl;
}

AForm::AForm(int gradeToSign, int gradeToExec, std::string name) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    _signed = false;
    if (gradeToSign < 1 || gradeToSign > 150)
        Bureaucrat::GradeTooHighException();
    else if (gradeToExec < 1 || gradeToExec > 150)
        Bureaucrat::GradeTooLowException();
    std::cout << "Special AForm Constructor Call" << std::endl;
}

AForm::AForm(AForm const &copy) : _name(copy._name + " Copy"), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	std::cout << "Copy AForm Constructor Call" << std::endl;
    *this = copy;
}

AForm &AForm::operator=(AForm const &other)
{
	this->_signed = other._signed;
    return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm Destructor Call" << std::endl;
}

std::string AForm::getName(void) const
{
    return (_name);
}

bool AForm::isSigned() const
{
    return (_signed);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExec() const
{
    return (_gradeToExec);
}

void    AForm::beSigned(Bureaucrat const &signer)
{
    if (signer.getGrade() > getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    std::cout << "AForm " << getName() << " is signed by " << signer.getName() << "." << std::endl;
    _signed = true;
}

void	AForm::checkSignAndExec(Bureaucrat const &executor) const
{
    if (!isSigned())
        throw Bureaucrat::SignedException();
    if (executor.getGrade() > getGradeToExec())
        throw Bureaucrat::GradeTooLowException();
}

std::ostream& operator<<(std::ostream &o, const AForm &ref)
{
	o << "AForm name: " << ref.getName() << std::endl << " grade required to sign: " << ref.getGradeToSign() << std::endl << " grade required to execute: " << ref.getGradeToExec();
    return (o);
}