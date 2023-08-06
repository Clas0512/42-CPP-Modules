#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

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
		class FormIsAlreadySigned : public std::exception{
			virtual const char* what() const throw(){
				return ("Form is already signed");
			}
		};
		void	beSigned(Bureaucrat const &signer);
};
std::ostream &operator<<(std::ostream &o, const Form &ref);

#endif