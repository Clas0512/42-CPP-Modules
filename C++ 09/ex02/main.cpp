#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    if (ac >= 3)
    {
        try
        {
            PmergeMe main(av, ac);
            main.printSeq();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    else
        std::cout << "Error: please enter 3 or more argument." << std::endl;
    return (0);
}