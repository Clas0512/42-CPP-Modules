#include "Form.hpp"

Form::Form() : _name("Unknown"), _gradeToSign(150), _gradeToExec(150)
{
    _signed = false;
	std::cout << "Default Constructor Call" << std::endl;
}

Form::Form(int gradeToSign, int gradeToExec, std::string name) : _name(name), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
    std::cout << "Special Constructor Call" << std::endl;
}

Form::Form(Form const &copy) : _name(copy._name), _gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	std::cout << "Copy Constructor Call" << std::endl;
    *this = copy;
}

Form &Form::operator=(Form const &other)
{
	this->_signed = other._signed;
    return (*this);
}

Form::~Form(void)
{
	std::cout << "Copy Destructor Call" << std::endl;
}

std::string Form::getName(void) const
{
    return (_name);
}

bool Form::isSigned() const
{
    return (_signed);
}

int Form::getGradeToSign() const
{
    return (_gradeToSign);
}

int Form::getGradeToExec() const
{
    return (_gradeToExec);
}

void    Form::beSigned(Bureaucrat const &signer)
{
    if (signer.getGrade() > getGradeToSign())
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << "Form " << getName() << " is signed by " << signer.getName() << "." << std::endl;
}

std::ostream& operator<<(std::ostream &o, const Form &ref)
{
	o << "Form name: " << ref.getName() << std::endl << " grade required to sign: " << ref.getGradeToSign() << std::endl << " grade required to execute: " << ref.getGradeToExec();
    return (o);
}