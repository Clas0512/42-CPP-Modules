#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
        std::cout << "Invalid argument!" << std::endl;
    else
    {
        std::string str(av[1]);
        if (ScalarConverter::convert(str))
            std::cout << "true" << std::endl;
        else
            std::cout << "false" << std::endl;
    }
    return (0);
}