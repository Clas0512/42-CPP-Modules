#include "PmergeMe.hpp"

// ---------------------------------------------------------------------------

PmergeMe::PmergeMe() : seqLen(0)
{
    std::cout << "Default Constructor Call" << std::endl;
}

PmergeMe::PmergeMe(const PmergeMe& copy) : seqLen(copy.getSeqLen())
{
    std::cout << "Copy Constructor Call" << std::endl;
    *this = copy;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    std::cout << "Operator Overload Call" << std::endl;
    this->vecArr = rhs.vecArr;
    this->listArr = rhs.listArr;
    this->vectorTime = rhs.vectorTime;
    this->listTime = rhs.listTime;
    this->seq = new int[rhs.seqLen];
    std::copy(rhs.seq, rhs.seq + seqLen, seq);
    return (*this);
}

PmergeMe::~PmergeMe()
{
    delete[] seq;
}


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
        catch (const std::exception &e)
        {
            throw MyException("Error: stoi.");
        }
        isPositive(seq[i]);
    }
}


// ---------------------------------------------------------------------------


void PmergeMe::createContainers(void)
{
    for (size_t i = 0; i < this->seqLen + 1; i++)
    {
        vecArr.push_back(this->seq[i]);
    }
    for (size_t i = 0; i < this->seqLen; i++)
    {
        listArr.push_back(this->seq[i]);
    }
    std::cout << "\n";
}

std::vector<int>& PmergeMe::getVec(void)
{
    return(this->vecArr);
}

size_t PmergeMe::getSeqLen(void) const
{
    return (this->seqLen);
}


// --------------------------------------------------------------------------------


void PmergeMe::printSeq(void) const
{
    for (size_t i = 0; i < this->seqLen; i++)
        std::cout << this->seq[i] << " ";
    std::cout << std::endl;
}

void PmergeMe::printVec(void) const
{
    for (std::vector<int>::const_iterator it = this->vecArr.begin(); it != this->vecArr.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printList(void) const
{
    for (std::list<int>::const_iterator it = this->listArr.begin(); it != this->listArr.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

double  PmergeMe::getVectorTime(void) const
{
    return (this->vectorTime);
}

double  PmergeMe::getListTime(void) const
{
    return (this->listTime);
}


// --------------------------------------------------------------------------------


void isPositive(long long number)
{
    if (number < 0 || number > 2147483647)
        throw PmergeMe::MyException("Error: arguments must be positive integer.");
}


// --------------------------------------------------------------------------------


void    PmergeMe::goSort()
{
    clock_t start = clock();
    this->mergeVectorSort(0, this->seqLen - 1);
    clock_t end = clock();
    this->vectorTime = (double)(end - start);
    clock_t start2 = clock();
    this->mergeList(this->listArr);
    clock_t end2 = clock();
    this->listTime = (double)(end2 - start2);
    this->vecArr.pop_back();
}


// --------------------------------------------------------------------------------


void PmergeMe::mergeVectorSort(int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeVectorSort(left, middle);
        mergeVectorSort(middle + 1, right);

        mergeVector(left, middle, right);
    }
}

void PmergeMe::mergeVector(int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = this->vecArr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = this->vecArr[middle + 1 + j];
    
    int i = 0;
    int j = 0;
    int k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            this->vecArr[k] = leftArr[i];
            i++;
        }
        else
        {
            this->vecArr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        
        this->vecArr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        this->vecArr[k] = rightArr[j];
        j++;
        k++;
    }
}


// --------------------------------------------------------------------------------


void PmergeMe::mergeListSort(std::list<int>& lst, std::list<int>& left, std::list<int>& right)
{
    std::list<int>::iterator leftIt = left.begin();
    std::list<int>::iterator rightIt = right.begin();

    while (leftIt != left.end() && rightIt != right.end())
    {
        if (*leftIt <= *rightIt)
        {
            lst.push_back(*leftIt);
            leftIt++;
        }
        else
        {
            lst.push_back(*rightIt);
            rightIt++;
        }
    }

    while (leftIt != left.end())
    {
        lst.push_back(*leftIt);
        leftIt++;
    }

    while (rightIt != right.end())
    {
        lst.push_back(*rightIt);
        rightIt++;
    }
}

void PmergeMe::mergeList(std::list<int>& lst)
{
    if (lst.size() < 2)
        return ;

    int middle = lst.size() / 2;
    std::list<int> left(lst.begin(), std::next(lst.begin(), middle));
    std::list<int> right(std::next(lst.begin(), middle), lst.end());

    mergeList(left);
    mergeList(right);

    lst.clear();
    mergeListSort(lst, left, right);
}
