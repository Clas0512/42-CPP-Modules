#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat A("adem", 151);
        std::cout << "A: " << A.getName() << std::endl;
        std::cout << "A: " << A.getGrade() << std::endl;
        std::cout << A << std::endl;
        A.decrementGrade();
        A.decrementGrade();
        std::cout << A.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << END << std::endl;
    }

    return (0);
}