#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <ctime>

class PmergeMe{
    private:
        std::vector<int>    vecArr;
        std::list<int>      listArr;
        int                 *seq;
        size_t              seqLen;
        double              vectorTime;
        double              listTime;
    public:
        PmergeMe();
		PmergeMe(const 	PmergeMe& copy);
		PmergeMe &operator=(PmergeMe const &rhs);
		~PmergeMe();
        PmergeMe(char **arguments, int ac);
        std::vector<int>& getVec(void);
        void    printSeq(void) const;
        void    printVec(void) const;
        void    printList(void) const;
        size_t  getSeqLen(void) const;
        double  getVectorTime(void) const;
        double  getListTime(void) const;
        class MyException : public std::exception{
            private:
                const char* errorStr;
            public:
                MyException(const char* _errorStr) : errorStr(_errorStr){};
                const char *what() const throw(){
                    return (errorStr);
                };
        };
        void    mergeVectorSort(int left, int right);
        void    mergeVector(int left, int middle, int right);
        void    createContainers(void);
        void    goSort(void);
        void    mergeListSort(std::list<int>& lst, std::list<int>& left, std::list<int>& right);
        void    mergeList(std::list<int>& lst);
};

void    isPositive(long long number);

#endif