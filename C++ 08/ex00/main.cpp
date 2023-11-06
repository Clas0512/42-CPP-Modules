#include "easyfind.hpp"

int main()
{

    std::vector<int> array;
    std::vector<int>::iterator itr; 

    for (size_t i = 0; i < 10; i++)
    {
       array.push_back(i);
    }

    try {
        itr = easyfind(array, 4);
        std::cout << "itr: " << *itr << std::endl;

        itr = easyfind(array, 10);
        std::cout << "itr: " << *itr << std::endl;
    }
    catch (noInArray &excpt)
    {
        std::cout << excpt.what() << std::endl;
    }

    return (0);
}