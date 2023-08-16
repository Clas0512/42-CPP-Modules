#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void	nl(void)
{
	std::cout << std::endl;
}

int main()
{
	try
	{
		std::cout << BLUE << "--------- Shrubbery ---------" << END << std::endl;
		Bureaucrat A("Adem", 15);
		nl();
		AForm *z = new ShrubberyCreationForm("talhaaksoyfenabirkral");
		nl();
		A.signForm(*z);
		nl();
		A.executeForm(*z);
		nl();
	
		delete z;
	
		nl();
		nl();

		std::cout << BLUE << "--------- Robotomy ---------" << END << std::endl;
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

		std::cout << BLUE << "--------- Presidential ---------" << END << std::endl;
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