#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <deque>
#include <stack>

class RPN : public std::deque<int>
{
    private:
        std::string		argument;
		std::deque<std::string> elements;
    public:
        RPN(std::string& str) : std::deque<int>(){
			this->argument = str;
		};
        RPN(const RPN& copy) : std::deque<int>(copy){};
		void	split(void);
		void	check(void);
		void	calculate(void);
		class ErrorException : public std::exception {
			private:
				const char *exceptionStr;
			public:
				ErrorException(const char *inputStr) : exceptionStr(inputStr) {};
				const char *what() const throw(){
					return (exceptionStr);
				}
		};

};

bool	isNumber(std::string str);
bool	isOperator(std::string str);

#endif