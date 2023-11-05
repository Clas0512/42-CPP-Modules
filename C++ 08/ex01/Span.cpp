#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N)
{
    std::cout << "Span is made with size " << N << std::endl;
}

void	Span::addNumber(int number)
{
    if (numbers.size() == this->maxSize)
        throw BoundOfArray();
	numbers.push_back(number);
}

void    Span::addNumber(int *number, int len)
{
    for (int i = 0; i < len; i++)
        addNumber(number[i]);
}

void    Span::printNumbers(void)
{
    std::vector<int>::iterator itr;
    for (itr = numbers.begin(); itr != numbers.end(); itr++)
        std::cout << *itr << std::endl;
}

int    Span::shortestSpan(void)
{
    int shortestSpan;
    int tempShortestSpan;

    if (numbers.size() < 2)
        throw notANumberForCmp();

    shortestSpan = std::abs(numbers.at(1) - numbers.at(0));
    for (std::vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++)
        for (std::vector<int>::iterator j = numbers.begin(); j != numbers.end(); j++)
        {
            if (i == j)
                continue ;
            tempShortestSpan = std::abs(*i - *j);
            if (shortestSpan > tempShortestSpan)
                shortestSpan = tempShortestSpan;
        }
    return (shortestSpan);
}

int    Span::longestSpan(void)
{
    int longestSpan;
    int tempLongestSpan;

    if (numbers.size() < 2)
        throw notANumberForCmp();
    
    longestSpan = 0;
    for (std::vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++)
        for (std::vector<int>::iterator j = numbers.begin(); j != numbers.end(); j++)
        {
            if (i == j)
                continue ;
            tempLongestSpan = std::abs(*i - *j);
            if (longestSpan < tempLongestSpan)
                longestSpan = tempLongestSpan;
        }
    return (longestSpan);
}

