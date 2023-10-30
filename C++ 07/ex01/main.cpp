#include "iter.hpp"

void printInteger(const int &a)   
{
    std::cout << a << std::endl;
}

void sumWithOne(int &a)
{
    a += 1;
}


int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    size_t g = 5;


    iter(array, g, sumWithOne);

    iter(array, g, printInteger);
    
}