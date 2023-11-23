#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
		std::string str(av[1]);
        RPN		obj(str);
		RPN		fake(obj);
		try
		{
			fake.split();
			fake.check();
			fake.calculate();
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