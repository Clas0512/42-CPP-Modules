#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "Debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Error" << std::endl;
}

void Harl::complain(std::string level){
	void (Harl::*f)() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			(this->*f[i])();
	}
}