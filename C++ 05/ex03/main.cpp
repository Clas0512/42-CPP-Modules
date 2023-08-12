#include "Intern.hpp"
void	nl()
{
	std::cout << std::endl;
}

int main()
{
	try
	{
		Bureaucrat A("Adem", 1);
		Intern i;
		AForm *frm;
		frm = i.makeForm("shrubberyCreation", "ademberke");
		A.signForm(*frm);
		A.executeForm(*frm);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}