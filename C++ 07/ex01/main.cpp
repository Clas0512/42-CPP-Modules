#include "iter.hpp"

void printInteger(int *a)
{
    std::cout << *a << std::endl;
}

void sumWithOne(int *a)
{
    (*a) += 1;
}

int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};


    iter(array, 5, sumWithOne);

    iter(array, 5, printInteger);
    
}