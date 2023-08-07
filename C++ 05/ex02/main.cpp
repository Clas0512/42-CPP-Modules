#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A("Student anargul", 75);
		Bureaucrat X("Staff X", 10);
		Form c(3, 3, "Staff Assignment");
		Form d(75, 3, "Student Assignment");
		Form e(c);
		Form f(d);

		std::cout << std::endl;

		X.signForm(c);
		std::cout << "c is signed ?" << std::endl << c.isSigned() << std::endl << std::endl;

		X.signForm(d);
		std::cout << "d is signed ?" << std::endl << d.isSigned() << std::endl << std::endl;
		A.signForm(e);
		std::cout << "e is signed ?" << std::endl << e.isSigned() << std::endl << std::endl;
		A.signForm(f);
		std::cout << "f is signed ?" << std::endl << f.isSigned() << std::endl << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}