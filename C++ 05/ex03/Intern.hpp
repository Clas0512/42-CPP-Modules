#ifndef INTERN_HPP
# define INTERN_HPP

# include "Bureaucrat.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const &copy);
		Intern &operator=(Intern const &other);
		~Intern(void);
        AForm *makeForm(std::string formName, std::string target);
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};
typedef AForm*(*funcArray)(std::string);

#endif
