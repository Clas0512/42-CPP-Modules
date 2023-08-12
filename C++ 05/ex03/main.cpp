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
		i.makeForm("shrubberyCreation", "ademberke");
		A.signForm(i);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}