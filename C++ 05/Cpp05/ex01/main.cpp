#include "Bureaucrat.hpp"

int main()
{

	Bureaucrat A("Student anargul", 75);
	Bureaucrat X("Staff X", 1);
	Form c(3, 3, "Staff Assignment");
	Form d(75, 3, "Student Assignment");

	std::cout << std::endl << A.getName() << " tries to sign some forms.." << std::endl;
	
	std::cout << A.getName() << "signs "
	A.signForm(d);
	std::cout << std::endl;

	return (0);
}