#include "RPN.hpp"

// --------------------------------------------------------------------------------

RPN::RPN(void)
{
    std::cout << "Default Constructor Call" << std::endl;
}

RPN::RPN(std::string& str) : std::deque<int>()
{
	this->argument = str;
}

RPN::RPN(const 	RPN& copy) : std::deque<int>(copy)
{
	this->argument = copy.argument;
}

RPN &RPN::operator=(RPN const &rhs)
{
    std::cout << "Operator Overload Call" << std::endl;
	this->argument = rhs.argument;
	return (*this);
}

RPN::~RPN(void)
{
    std::cout << "Default Destructor Call" << std::endl;
}


// --------------------------------------------------------------------------------


bool	isNumber(std::string str)
{
	int	convertedInt;
	try
	{
		convertedInt = std::stoi(str);
	}
	catch(const std::exception& e)
	{
		return (false);
	}
	return (true);
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
	int numberCount = 0;
	int operatorCount = 0;

	it = this->elements.begin();
	for(; it != this->elements.end(); it++)
	{
		if ((*it).size() != 1)
			throw RPN::ErrorException("Error: expression cannot contain anything except for an operator or number.");
		if (isNumber(*it))
			numberCount++;
		if (isOperator(*it))
			operatorCount++;
		if (it == this->elements.begin() && isNumber(*it) == false)
			throw RPN::ErrorException("Error: expression cannot start without number.");
		if ((it + 1) == this->elements.end() && isOperator(*it) == false)
			throw RPN::ErrorException("Error: expression cannot end without operator.");
		if (isNumber(*it) == false && isOperator(*it) == false)
			throw RPN::ErrorException("Error: expression cannot contain anything except for an operator or number.");
	}
	if (operatorCount != (numberCount - 1))
		throw RPN::ErrorException("Error: invalid input.");
}

std::string doInst(int first, int second, std::string oprtr)
{
	std::string returnStr;
	if (oprtr == "+")
		returnStr = std::to_string(first + second);
	if (oprtr == "-")
		returnStr = std::to_string(first - second);
	if (oprtr == "*")
		returnStr = std::to_string(first * second);
	if (oprtr == "/"){
		if (second == 0)
			throw RPN::ErrorException("Error: you cannot divide by 0");
		returnStr = std::to_string(first / second);
	}
	return (returnStr);
}

void	RPN::calculate(void)
{
	std::stack<std::string> stackk;
	std::deque<std::string>::iterator beginItr;
	std::deque<std::string>::iterator endItr;

	beginItr = this->elements.begin();
	while (beginItr != endItr && isNumber(*beginItr) == true)
	{
		if (stackk.size() == 0 && this->elements.size() == 1)
			break ;
		if (isNumber(this->elements.front()) == true)
		{
			while (beginItr != endItr && isOperator(this->elements.front()) == false)
			{
				stackk.push(this->elements.front());
				this->elements.pop_front();
				beginItr = this->elements.begin();
			}
			if (stackk.size() < 2 || this->elements.size() <= 0)
				throw ErrorException("Error: invalid arguments.");
			while (beginItr != endItr && isNumber(this->elements.front()) == false && stackk.size() >= 2)
			{
				int second = std::stoi(stackk.top());
				stackk.pop();
				int first = std::stoi(stackk.top());
				stackk.pop();
				std::string oprtr = this->elements.front();
				this->elements.pop_front();
				stackk.push(doInst(first, second, oprtr));
				beginItr = this->elements.begin();
			}
			while (stackk.size() != 0)
			{
				this->elements.push_front(stackk.top());
				stackk.pop();
			}
		}
	}
	std::cout << this->elements.front() << std::endl;
}

void	RPN::split(void)
{
	std::string tmpStr;
	std::istringstream iss(this->argument);

	while (iss >> tmpStr)
		this->elements.push_back(tmpStr);
}
