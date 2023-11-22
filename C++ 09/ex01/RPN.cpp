#include "RPN.hpp"

bool	isNumber(std::string str)
{
	int	convertedInt;
	if (str.length() == 1)
	{
		try
		{
			convertedInt = std::stoi(str);
		}
		catch(const std::exception& e)
		{
			return (false);
		}
		if (convertedInt > 9 || convertedInt < 0)
			return (false);
		else
			return (true);
	}
	else
		return (false);
}

bool	isOperator(std::string str)
{
	if (str == "+" || str == "-" || str == "*" || str == "/")
		return (true);
	else
		return (false);
}

void	RPN::check(void)
{
	std::deque<std::string>::iterator	it;

	it = this->elements.begin();
	for(; it != this->elements.end(); it++)
	{
		if (it == this->elements.begin() && isNumber(*it) == false)
			throw RPN::ErrorException("Error: expression cannot start without number.");
		if ((it + 1) == this->elements.end() && isOperator(*it) == false)
			throw RPN::ErrorException("Error: expression cannot end without operator.");
		if (isNumber(*it) == false || isOperator(*it) == false)
			throw RPN::ErrorException("Error: expression cannot contain anything except for an operator or number.");
	}
}

void	RPN::calculate(void)
{
	std::stack<std::string> operants;
	std::deque<std::string>::iterator beginItr;
	std::deque<std::string>::iterator endItr;

	beginItr = this->elements.begin();
	while (beginItr != endItr)
	{
		if (isNumber(this->elements.front()) == true)
		{
			for	(; beginItr != endItr && isOperator(this->elements.front()) == false; beginItr++)
			{
				operants.push(this->elements.front());
				this->elements.pop_front();
				beginItr = this->elements.begin();
			}
			if (operants.size() < 2)
				throw ErrorException("Error: invalid arguments.");
		}
	}
}

void	RPN::split(void)
{
	std::string tmpStr;
	std::istringstream iss(this->argument);

	while (iss >> tmpStr)
		this->elements.push_back(tmpStr);
}
