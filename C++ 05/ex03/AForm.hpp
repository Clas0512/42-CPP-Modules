#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
        std::string const _name;
        bool _signed;
		int const _gradeToSign;
		int const _gradeToExec;
	public:
		AForm();
		AForm(int gradeTosign, int gradeToExec, std::string name);
		AForm(AForm const &copy);
		AForm &operator=(AForm const &other);
		virtual ~AForm();
		std::string getName(void) const;
		bool isSigned() const ;
		int getGradeToSign() const ;
		int getGradeToExec() const ;
		void	beSigned(Bureaucrat const &signer);
		virtual void    execute(Bureaucrat const & executor) const = 0;
		void	checkSignAndExec(Bureaucrat const &executor) const;

};
std::ostream &operator<<(std::ostream &o, const AForm &ref);

#endif