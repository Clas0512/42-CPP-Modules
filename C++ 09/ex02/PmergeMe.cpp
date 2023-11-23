#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **arguments, int ac) : seqLen(ac - 1)
{
    this->seq = new int[this->seqLen];
    for (size_t i = 0; i < seqLen; i++)
    {
        std::string tmp(arguments[i + 1]);
        try
        {
            for (size_t i = 0; tmp[i]; i++)
                if (!isdigit(tmp[i]))
                    throw std::exception();
            seq[i] = std::stoi(tmp);
        }
        catch(const std::exception& e)
        {
            throw MyException("Error: stoi.");
        }
        isPositive(seq[i]);
    }
}

void    PmergeMe::printSeq(void)
{
    for (size_t i = 0; i < this->seqLen; i++)
        std::cout << this->seq[i] << std::endl;
}

void    isPositive(long long number)
{
    if (number < 0 || number > 2147483647)
        throw PmergeMe::MyException("Error: arguments must be positive integer.");
}
