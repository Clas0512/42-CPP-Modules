#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG: I really enjoy adding extra bacon, but it seems to be increasing my car's fuel consumption. I suppose I should be more careful." << std::endl;
}

void Harl::info(void)
{
	std::cout << "INFO: The cost of additional vehicle accessories took me by surprise. However, I noticed serious errors during the installation of these extras. This situation has truly disappointed me." << std::endl;
}

void Harl::warning(void)
{
	std::cout << "WARNING: It's not appropriate to demand such a high price for extra accessories. Furthermore, I have concerns about safety due to installation errors in the vehicle. I would advise you to be more cautious." << std::endl;
}

void Harl::error(void)
{
	std::cout << "ERROR: This is an absolute disaster! I haven't received any value for the money I paid for the extra features. Moreover, the problems that arose during the car's repair are quite distressing. I would like to speak with a manager immediately to find a resolution." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*f[4])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int	zort = 0;

	while (zort < 4)
	{
		if (level == levels[zort])
			break ;
		zort++;
	}

	switch (zort)
	{
		case 0:
			(this->*f[0])();
		case 1:
			(this->*f[1])();
		case 2:
			(this->*f[2])();
		case 3:
			(this->*f[3])();
	}
}