#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat A("adem", 149);
    std::cout << "A: " << A.getName() << std::endl;
    std::cout << "A: " << A.getGrade() << std::endl;

    std::cout << A << std::endl;

    try
    {
        A.decrementGrade();
        A.decrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << RED << e.what() << END << std::endl;
    }

    std::cout << A.getGrade() << std::endl;
    return (0);
}