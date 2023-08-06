#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat A("adem", 1);

    std::cout << A.getName() << std::endl;
    std::cout << A.getGrade() << std::endl;

    std::cout << A << std::endl;

    try
    {
        A.incrementGrade();
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << A.getGrade() << std::endl;
    return (0);
}