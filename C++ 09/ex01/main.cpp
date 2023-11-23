#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
		std::string str(av[1]);
        RPN		obj(str);
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