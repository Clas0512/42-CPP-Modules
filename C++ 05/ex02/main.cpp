#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	nl()
{
	std::cout << std::endl;
}

int main()
{
	try
	{
		Bureaucrat A("Adem", 150);
		nl();
		AForm *z = new ShrubberyCreationForm("HAHAHAHA!");
		nl();
		A.signForm(*z);
		nl();
		A.executeForm(*z);
		nl();
	
		delete z;
	
		nl();
		nl();

		Bureaucrat B("B", 1);
		AForm *az = new RobotomyRequestForm("zazaza!");
		nl();
		B.signForm(*az);
		nl();
		B.executeForm(*az);
		nl();
		delete az;

		nl();
		nl();

		Bureaucrat C("C", 5);
		AForm *abc = new PresidentialPardonForm("komkom..");
		nl();
		C.signForm(*abc);
		nl();
		C.executeForm(*abc);
		nl();
		delete abc;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}