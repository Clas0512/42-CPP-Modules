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
		nl();
		Intern i;
		nl();
		AForm *frm;
		nl();
		frm = i.makeForm("rasd", "ademberke");
		nl();
		A.signForm(*frm);
		nl();
		A.executeForm(*frm);
		nl();
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << END << std::endl;
	}

	return (0);
}