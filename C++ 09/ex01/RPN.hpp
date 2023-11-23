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
		RPN(void);
		RPN(const 	RPN& copy);
		RPN &operator=(RPN const &rhs);
		~RPN(void);
        RPN(std::string& str);
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