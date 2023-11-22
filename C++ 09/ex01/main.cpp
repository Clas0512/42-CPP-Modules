#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        RPN		obj(av[1]);
        std::string		*elements;

		try
		{
			obj.split();
			obj.check();
			obj.calculate();
		}
		catch(const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
    }
    else
        std::cout << "Error: invalid input." << std::endl;
    return 0;
}