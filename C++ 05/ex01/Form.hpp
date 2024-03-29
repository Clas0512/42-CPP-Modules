#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"
# include <fstream>
# include <string>

class Bureaucrat;

class Form
{
	private:
        std::string const _name;
        bool _signed;
		int const _gradeToSign;
		int const _gradeToExec;
	public:
		Form();
		Form(int gradeTosign, int gradeToExec, std::string name);
		Form(Form const &copy);
		Form &operator=(Form const &other);
		virtual ~Form();
		std::string getName(void) const;
		bool isSigned() const ;
		int getGradeToSign() const ;
		int getGradeToExec() const ;
		void	beSigned(Bureaucrat const &signer);
};
std::ostream &operator<<(std::ostream &o, const Form &ref);

#endif