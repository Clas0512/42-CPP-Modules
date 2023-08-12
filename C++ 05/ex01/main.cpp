#include "Bureaucrat.hpp"

void nl(void)
{
	std::cout << std::endl;
}

int main()
{
	try
	{
		Bureaucrat A("Student anargul", 70);
		Bureaucrat X("Staff X", 10);
		Form c(3, 3, "Staff Assignment");
		Form d(75, 3, "Student Assignment");
		Form e(c);
		Form f(d);

		nl();
		A.signForm(d);
		nl();
		X.signForm(c);
		nl();
		std::cout << "c is signed ?" << std::endl << c.isSigned() << std::endl;
		nl();
		X.signForm(d);
		nl();
		std::cout << "d is signed ?" << std::endl << d.isSigned() << std::endl;
		nl();
		A.signForm(e);
		nl();
		std::cout << "e is signed ?" << std::endl << e.isSigned() << std::endl;
		nl();
		A.signForm(f);
		nl();
		std::cout << "f is signed ?" << std::endl << f.isSigned() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << RED << e.what() << END << std::endl;
	}
	return (0);
}