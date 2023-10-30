#include "iter.hpp"

# include <iostream>


void printInteger(const int &a)   
{
    std::cout << a << std::endl;
}

void sumWithOne(int &a)
{
    a += 1;
}

template<typename I, typename F, typename Z>
void iter(I *iArray, size_t length, F function(Z &element)){
    for (size_t i = 0; i < length; i++)
        function(iArray[i]);
}
int main(void)
{
    int array[5] = {1, 2, 3, 4, 5};
    size_t g = 5;


    iter(array, g, sumWithOne);

    iter(array, g, printInteger);
    
}