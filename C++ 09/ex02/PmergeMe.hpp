#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>

class PmergeMe{
    private:
        int *seq;
        const size_t seqLen;
    public:
        PmergeMe(char **arguments, int ac);
        void    printSeq();
        class MyException : public std::exception{
            private:
                const char* errorStr;
            public:
                MyException(const char* _errorStr) : errorStr(_errorStr){};
                const char *what() const throw(){
                    return (errorStr);
                };
        };
};

void    isPositive(long long number);

#endif